#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void Insertion_Sorted(struct node** head, int newData) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = NULL;

    struct node* Current = *head;
    struct node* Prev = NULL;

    while(Current != NULL && Current->data < newData) {
        Prev = Current;
        Current = Current->next;
    }

    if(Prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Prev->next = newNode;
        newNode->next = Current;
    }
}

void printLL(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void DisplayAddressLL(struct node* head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("Node val=%d, add=%p\t", ptr->data, (void*)ptr);
        printf("Next node add=%p\n", (void*)ptr->next);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int n, k;

    printf("Enter n: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int random = rand() % 100 + 1;
        printf("%d ", random);
        Insertion_Sorted(&head, random);
    }
    printf("\n");
    printLL(head); // before update

    printf("Address before inserting new node:\n");
    DisplayAddressLL(head);

    printf("Enter value of newnode: ");
    scanf("%d", &k);
    Insertion_Sorted(&head, k);

    printLL(head); // update

    printf("Address after inserting new node:\n");
    DisplayAddressLL(head);

    return 0;
}
