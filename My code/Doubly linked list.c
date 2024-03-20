#include<stdio.h>
#include<stdlib.h>

int choice;

struct node {
    int marks[3];
    char name[10];
    struct node *prev;
    struct node *next;
};
struct node *newnode = NULL, *head = NULL, *temp = NULL, *cur = NULL;

void create() {
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter details\n");
    scanf("%s%d", newnode->name, &newnode->marks[0]);
    head = newnode;
    newnode->next = NULL;
    newnode->prev = NULL;
}

void display() {
    if(head ==  NULL) {
        printf("Empty\n");
        exit(0);
    }
    temp = head;
    while(temp != NULL) {
        printf("%s %d\n\n", temp->name, temp->marks[0]);
        temp = temp->next;
    }
}

void insertfront() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter details\n");
    scanf("%s%d", newnode->name, &newnode->marks[0]);
    temp = head;
    head = newnode;
    newnode->next = temp;
    newnode->prev = NULL;
    temp->prev = newnode;
}

void deletefront(){
    temp = head;
    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }
    head = temp->next;
    if(head != NULL)
        head->prev = NULL;
    free(temp);
    temp = NULL;
}

void insertrear() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter details\n");
    scanf("%s%d", newnode->name, &newnode->marks[0]);
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
}

void deleterear() {
    temp = head;
    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    cur = temp->prev;
    if(cur != NULL)
        cur->next = NULL;
    free(temp);
    temp = NULL;
}

int main() {
    printf("Doubly Linked List\n");
    while(1) {
        printf("\n1. Create\n2. Insert front\n3. Delete front\n4. Insert rear\n5. Delete rear\n6. Display\n7. EXIT\n Enter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create();
            break;
            case 2: insertfront();
            break;
            case 3: deletefront();
            break;
            case 4: insertrear();
            break;
            case 5: deleterear();
            break;
            case 6: display();
            break;
            case 7: exit(0);
            break;
            default: printf("Invalid choice\n");
            exit(0);
        }
    }
    return 0;
}
