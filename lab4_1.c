#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void DisplayLL() {
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void DisplayAddressLL() {
    struct node *ptr;
    ptr = head;
    while (ptr!=NULL)
    {
        printf("Node val=%d, add=%p\t", ptr->data, ptr);
        printf("Next node add=%X\n",ptr->next);
        ptr = ptr->next;
    }
}
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0;i < n;i++) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = rand()%100+1;
        newNode->next = head;
        head = newNode;
    }
    DisplayLL();
    DisplayAddressLL();
    return 0;
}
