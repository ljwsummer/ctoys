
/**
 * @file remove_node.c
 * @author Jiawang Liu (ljwsummer@gmail.com)
 * @date 2013/02/04 15:25:33
 * @brief
 * an example of using pointers-to-pointers to remove nodes in linked list
 **/

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int value;
}; 

void
creat_list(node *head, int n) {
    int i = 0;
    node *tail = head;
    node *tmp;
    srand(1); // setup random seed
    for (i = 0; i < n; i++) {
        tmp = (node *)malloc(sizeof(node));
        tmp->value = rand()%10;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
    }
}

void
print_list(node *head) {
    node *curr = head;
    while (curr->next != NULL) {
        printf("%d->", curr->value);
        curr = curr->next;
    }
    printf("%d\n", curr->value);
}

typedef bool
(*remove_fn)(node const *v);

bool 
rm_cont_fn(node const *v) {
    return v->value > 5 ? true : false;
}

// remove all nodes from the list which the remove func returns true
// follow Linus Torvalds' advice. by Thomas Guest
void
remove_node(node **head, remove_fn rm) {
    for (node **curr = head; *curr; ) {
        node *entry = *curr;
        if (rm(entry)) {
            *curr = entry->next;
            free(entry);
        }
        else {
            curr = &entry->next;
        }
    }
}

int 
main(void) {
    node *head;
    head = (node *)malloc(sizeof(node));
    head->value = 0;
    head->next = NULL;
    creat_list(head, 20);
    printf("creat a linked list:\n");
    print_list(head);
    node **h = &head;
    remove_node(h, rm_cont_fn);
    printf("remove the nodes whose values are greater than 5:\n");
    print_list(*h);
    return 0;
}

