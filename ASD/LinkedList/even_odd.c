#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


void print_list(LinkedList *list, const char *message){
    printf("%s: ", message);
    Node *iterator = list->head;
    while(iterator != NULL){
        printf("%d ", iterator->value);
        iterator = iterator->next;
    }

    printf("\n");
}



void even_odd(LinkedList *list){
    Node *p1_head = NULL, *p1_tail = NULL;
    Node *p2_head = NULL, *p2_tail = NULL;

    Node *iterator=list->head;
    while(iterator != NULL){
        Node *next = iterator->next;
        iterator->next = NULL;
        if(iterator->value % 2 == 0){
            if(p1_head == NULL){
                p1_head = p1_tail = iterator;
            }
            else {
                p1_tail->next = iterator;
                p1_tail = iterator;
            }
        } 
        else {
            if(p2_head == NULL){
                p2_head = p2_tail = iterator;
            }
            else {
                p2_tail->next = iterator;
                p2_tail = iterator;
            }
        }
    
        iterator = next;
    }

    if(p1_tail) p1_tail->next = p2_head;
    list->head = (p1_head != NULL) ? p1_head : p2_head;


}


int main(){
    LinkedList l;
    l.head = NULL;
    l.size = 0;

    // Now try original sequence
    push_back(&l, 3);
    push_back(&l, 4);
    push_back(&l, 5);
    push_back(&l, 2);
    push_back(&l, 8);
    push_back(&l, 9);

    print_list(&l, "Before func");
    even_odd(&l);
    print_list(&l, "After func");

    return 0;
}
