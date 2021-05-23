#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "llist.h"

node *node_make(int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = n->prev = NULL;
    
    return n;
}

node *list_insert(node *prev_node, int value) {
    node *new_node = node_make(value);
    if (prev_node->next == NULL) {new_node->next = NULL;}
    else {new_node->next = prev_node->next;}
    prev_node->next = new_node;
    return new_node;
}

void list_print(const node *head) {
    node *current_node = head;
    printf("%d\n", head->value);
    while (current_node->next != NULL) {
        current_node = current_node->next;
        printf("%d\n", current_node->value);
    }
}

node *list_find(node *head, int value) {
    node *current_node = head;
    if (head->value == value) {
        return head;
    }
    while (current_node->next != NULL) {
        current_node = current_node->next;
        if (current_node->value == value) {
            return current_node;
        }
    }
    return NULL;
}

void list_remove(node *n) {
    if(n->prev) {
        n->prev->next = n->next;
    }
    
    if(n->next) {
        n->next->prev = n->prev;
    }
    free(n);
}

void list_free(node *head) {
    node *current_node = head->next;
    while (current_node != NULL) {
        free(current_node->prev);
        current_node = current_node->next;
    }
}