#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void print_list(LinkedList* list, const char* message) {
    printf("%s: ", message);
    Node* it = list->head;
    while (it != NULL) {
        printf("%d ", it->value);
        it = it->next;
    }
    printf("\n");
}

Node* merge(Node* left, Node* right) {
    Node* dummy = create_Node(0);
    Node* current = dummy;

    while (left != NULL && right != NULL) {
        if (left->value <= right->value) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    if (left != NULL) {
        current->next = left;
    } else {
        current->next = right;
    }

    Node* result = dummy->next;
    free(dummy);
    return result;
}



Node* merge_sort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* mid = get_mid(head);
    Node* left = merge_sort(head);
    Node* right = merge_sort(mid);

    return merge(left, right);
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

    print_list(&l, "Before sort");
    l.head = merge_sort(l.head);
    print_list(&l, "After sort");

    return 0;
}