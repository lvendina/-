#include <stdio.h>
#include <stdlib.h>


struct tNode {
    int data;
    struct tNode *next;
};
typedef struct tNode tNode;

struct tList {
    int size;
    tNode *head;
};
typedef struct tList tList;

tList * create_list(void) {
    tList *list = malloc(sizeof(tList));

    list->size = 0;
    list->head = NULL;

    return list;
}

void push_front(tList *list, int value) {
    tNode *Node = malloc(sizeof(tNode));
    Node->data = value;
    Node->next = list->head;

    list->head = Node;
    list->size += 1;
}

void delete_front(tList *list) {
    if (list->size == 0)
        return;

    tNode *t = list->head;

    list->head = list->head->next;

    free(t);
    list->size -=1;
}

void insert(tList *list, int index, int value) {
    if (index == 0)
        push_front(list, value);
    else {
        tNode *pred = list->head;
        for (int i = 0; i < index - 1; i++)
            pred = pred->next;

        tNode *Node = malloc(sizeof(tNode));
        Node->data = value;
        Node->next = pred->next;

        pred->next = Node;
        list->size += 1;
    }
}

void deleteAt(tList *list, int index) {
    if (index == 0)
        delete_front(list);
    else {
        tNode *previos = list->head;
        for (int i = 0; i < index - 1; i++)
            previos = previos->next;

        tNode *toDelete = previos->next;

        previos->next = toDelete->next;

        free(toDelete);
        list->size -=1;
    }
}

void print(tList *list) {

    tNode *print_node = list->head;
    while (print_node != NULL) {
        printf("%d\n", print_node->data);
        print_node = print_node->next;
    }

    Menu(list);
}

void add_node(tList *list) {
    int i;
    printf("Enter the item number from 1 to %d\n", list->size+1);
    while (scanf("%d", &i) != 1 || i < 1 || i > list->size+1)
        fflush(stdin);

    int data;
    printf("Enter data (number)\n");
    while (scanf("%d", &data) != 1)
        fflush(stdin);

    insert(list, i-1, data);
    printf("Item added!\n");

    Menu(list);
}

void delete_node(tList *list) {

    int i;
    printf("Enter the item number from 1 to %d\n", list->size);
    while (scanf("%d", &i) != 1 || i < 0 || i > list->size)
        fflush(stdin);

    deleteAt(list, i-1);
    printf("Item deleted!\n");

    Menu(list);
}

void Menu(tList *list) {
    int c = 3;
    printf("Click to add an item 1, for delete - 2, to display the list on the screen - 3\n");
    while (scanf("%d", &c) != 1 || c < 1 || c > 3)
        fflush(stdin);

    if (c == 1)
        add_node(list);
    if (c == 2)
        delete_node(list);
    if (c == 3)
        print(list);
}

int main(void) {

    tList *list = create_list();
    Menu(list);

    return 0;
}

