#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


Node * create_Node(int value){
    Node * NewNode = (Node *)malloc(sizeof(Node));

    NewNode->value = value;
    NewNode->next = NULL;

    return NewNode;
}

Node * get_Node(LinkedList* list, int index){
    Node * currentNode = list->head;

    for(int i = 0;i<index;i++) {
        currentNode = currentNode->next;
    }
    return currentNode;
}

Node* get_mid(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    }

    return slow;
}

void push_front(LinkedList* list, int value){
    Node * NewNode = create_Node(value);

    NewNode->next = list->head;
    list->head = NewNode;
    list->size++;
}

void push_at(LinkedList* list, int index, int value){
    if(index == 0){
        push_front(list,value);
    } else {
        Node * PrevNode = get_Node(list,index - 1);
        Node * NewNode = create_Node(value);

        NewNode->next = PrevNode->next;
        PrevNode->next = NewNode;
        list->size++;
    }
}

void push_back(LinkedList* list, int value) {
    Node* NewNode = create_Node(value);
    
    // If list is empty, set head
    if (list->head == NULL) {
        list->head = NewNode;
    } else {
        // Find last node
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        // Append new node
        current->next = NewNode;
    }
    list->size++;
}
