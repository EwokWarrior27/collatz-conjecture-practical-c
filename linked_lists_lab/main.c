#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

int main(int argc, char *argv[]) {
    // Try out your code as you're building it here.
    // If you just run "make" in this directory, it
    // will compile this file and make an executable
    // called "main".
    
    // When you've got most of the functions in place,
    // try compiling the tests with "make test" and
    // running them via the executable called "test".

    node *head = node_make(1);
    printf("I made a node @ %p, with value %d!\n", head, head->value);
    node *shoulders = list_insert(head, 2);
    printf("I made another node @ %p, with value %d!\n", shoulders, shoulders->value);
    list_print(head);
    if (list_find(head, 2) != NULL) {printf("got it\n");}
    node *knees = list_insert(shoulders, 3);
    list_remove(shoulders);
    list_print(head);
    free(knees);
    list_free(head);

    return 0;
}