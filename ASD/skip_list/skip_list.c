#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "skip_list.h"

SkipList *init(SkipList *list){
    int i;
    snode *header = (snode *)malloc(sizeof(struct snode));
    list->header = header;
    header->key = __INT_MAX__;
    header->forward = (snode **)malloc(sizeof(snode*) * (SKIPLIST_MAX_LEVEL + 1));

    for(i = 0;i <= SKIPLIST_MAX_LEVEL; i++){
        header->forward[i] = NULL;
    }


    list->level = 1;
    list->size = 0;

    return list;
}


static int rand_level(){
    int level = 1;
    while (rand() < RAND_MAX / 2 && level < SKIPLIST_MAX_LEVEL)
        level++;
    return level;
}

snode *search(SkipList *list, int key) {
    snode *x = list->header;
    int i;
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i] != NULL && x->forward[i]->key < key)
            x = x->forward[i];
    }
    if (x->forward[1] != NULL && x->forward[1]->key == key) {
        return x->forward[1];
    } else {
        return NULL;
    }
}


int push(SkipList *list, int key, int value){
    snode *update[SKIPLIST_MAX_LEVEL + 1];
    snode *x = list->header;
    int i, level;
    
    for(i = list->level; i >= 1; i--){
        while(x->forward[i] != NULL && x->forward[i]->key < key){
            x = x->forward[i];
        }
        update[i] = x;        
    }

    x = x->forward[1];

    if(x != NULL && key == x->key){
        x->value = value;
        return 0;
    } else {
        level = rand_level();
        if(level > list->level){
            for(i = list->level + 1; i <= level; i++){
                update[i] = list->header;
            }
            list->level = level;
        }

        x = (snode *)malloc(sizeof(snode));
        x->key = key;
        x->value = value;
        x->forward = (snode **)malloc(sizeof(snode *) * (level + 1));
        
        for(i = 1; i <= level; i++){
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x; 
        }
        
        list->size++; 
    }

    return 0;
}    


static void node_free(snode *x){
    if(x){
        free(x->forward);
        free(x);
    }
}


int pop(SkipList *list, int key){
    int i;
    snode *update[SKIPLIST_MAX_LEVEL + 1];
    snode *x = list->header;

    for(i = list->level; i >= 1; i--){
        while(x->forward[i] != NULL && x->forward[i]->key < key){
            x = x->forward[i];
        }
        update[i] = x;
    }

    x = x->forward[1];
    if(x != NULL && x->key == key){
        for(i = 1; i <= list->level; i++){
            if(update[i]->forward[i] != x){
                break;
            }
            update[i]->forward[i] = x->forward[i];
        }
        node_free(x);
        list->size--;

        while(list->level > 1 && list->header->forward[list->level] == NULL){
            list->level--;
        }
        return 0;
    }
    return 1;
}


static void slist_print(SkipList *list){
    snode *x = list->header->forward[1];
    while(x != NULL){
        printf("%d[%d]->", x->key, x->value);
        x = x->forward[1];
    }
    printf("NIL\n");
}




void reverse_slist(SkipList *list){
    snode *current = list->header->forward[1];
    snode *next = NULL;
    snode *prev = list->header;
    
    // Reverse the base level (level 1)
    while(current != NULL){
        next = current->forward[1];
        current->forward[1] = prev;
        prev = current;
        current = next;
    }
    
    // Update header to point to last node
    list->header->forward[1] = prev;
    
    // Rebuild higher levels
    int i;
    for(i = 2; i <= list->level; i++){
        list->header->forward[i] = NULL;
    }
    
    // Re-insert nodes at higher levels randomly
    current = list->header->forward[1];
    while(current != NULL && current != list->header){
        int level = rand_level();
        if(level > list->level){
            for(i = list->level + 1; i <= level; i++){
                list->header->forward[i] = NULL;
            }
            list->level = level;
        }
        
        // Update forward pointers for higher levels
        for(i = 2; i <= level; i++){
            current->forward[i] = list->header->forward[i];
            list->header->forward[i] = current;
        }
        
        current = current->forward[1];
    }
}







int main(){
    int arr[] = {3,6,9,2,11,1,4}, i;
    SkipList list;
    init(&list);
    
    
    printf("INSERT--------------------------\n");
    for(i = 0; i < sizeof(arr) / sizeof(arr[0]);i++){
        push(&list, arr[i], arr[i]);
    }

    slist_print(&list);

    printf("SEARCH--------------------------\n");
    int keys[] = {3,4,7,10,111};
    for(i = 0;i<sizeof(keys) / sizeof(keys[0]);i++){
        snode *x = search(&list, keys[i]);
        if(x){
            printf("key = %d, value = %d\n", keys[i], x->value);
        } else{
            printf("key = %d, not found\n", keys[i]);
        }

    }

    printf("SEARCH--------------------------\n");
    pop(&list, 3);
    pop(&list, 9);
    slist_print(&list);

    return 0;
}
