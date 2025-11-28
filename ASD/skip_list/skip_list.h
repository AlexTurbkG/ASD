#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#define SKIPLIST_MAX_LEVEL 6

typedef struct snode{
    int key;
    int value;
    struct snode **forward;
} snode;


typedef struct SkipList{
    int level;
    int size;
    struct snode *header; 
} SkipList;


SkipList *init(SkipList *list);
int push(SkipList *list, int key, int value);
int pop(SkipList *list, int key);
void reverse(SkipList *list);



#endif