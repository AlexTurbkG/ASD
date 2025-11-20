#ifndef LINKED_LIST_H
#define LINKED_LIST_H



typedef struct Node {
  int value;
  struct Node * next;
} Node;

typedef struct {
  struct Node * head;
  int size;
} LinkedList;

void push_back(LinkedList* list, int value);
void push_at(LinkedList* list, int index, int value);
void push_front(LinkedList* list, int value);
Node * get_Node(LinkedList* list, int index);
Node * create_Node(int value);
Node * get_mid(Node *head);

#endif