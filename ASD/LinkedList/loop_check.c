#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

bool hasLoop(Node * head){
    Node *it1 = head;
    Node *it2 = head;

    
    while(it2 && it2->next){
        it2 = it2->next->next;
        it1 = it1->next;
        if(it1 == it2) return 1;
    }
    return 0;
}


