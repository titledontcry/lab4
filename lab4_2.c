#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};

int search_item(struct node* head, int x) {
    struct node* current = head;
    int position = 1;
    while(current != NULL) {
        if(current->data == x) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}
struct node* newNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct node* createLL() {
    struct node* head = newNode(10);
    head->next = newNode(2);
    head->next->next = newNode(33);
    head->next->next->next = newNode(-3);
    head->next->next->next->next = newNode(65);
    head->next->next->next->next->next = newNode(67);
    return head;
}

int main() {
    struct node* head = createLL();

    printf("%d\n",search_item(head, 65));
    printf("%d\n",search_item(head, 50));
    return 0;
}