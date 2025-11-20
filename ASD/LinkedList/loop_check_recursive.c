#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"


bool hasLoopRecursive(Node * head, Node *it2){
    if(it2 == NULL || it2->next == NULL) return 0;

    if(head == it2) return 1;
    else hasLoopRecursive(head->next, it2->next->next);
}                                                         
