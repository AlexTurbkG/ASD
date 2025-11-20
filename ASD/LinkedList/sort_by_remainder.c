#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int k = 2;


void print_list(LinkedList* list, const char* message) {
    printf("%s: ", message);
    Node* it = list->head;
    while (it != NULL) {
        printf("%d ", it->value);
        it = it->next;
    }
    printf("\n");
}


void sort_by_remainder(LinkedList* list){
    Node *head = NULL;
    Node *tail = NULL;


    for(int remainder = 0;remainder < k;remainder++){
        Node *current = list->head;
        Node *prev = NULL;

        while(current != NULL) {
            Node *next = current->next;

            if(current->value % k == remainder) {
                if(prev) {
                    prev->next = next;
                }
                else {
                    list->head = next;
                }

                current->next = NULL;
                if(!head) {
                    head = tail = current;
                }
                else {
                    tail->next = current;
                    tail = current;
                }
            } 
            
            else {
                prev = current;
            }

            current = next;
        } 
    }
    list->head = head;

}







int main(){

    LinkedList l;
    l.head = NULL;
    l.size = 0;

    push_back(&l, 3);
    push_back(&l, 4);
    push_back(&l, 5);
    push_back(&l, 2);
    push_back(&l, 8);
    push_back(&l, 0);

    print_list(&l, "before func");

    sort_by_remainder(&l);

    print_list(&l, "after func");


    return 0;
}