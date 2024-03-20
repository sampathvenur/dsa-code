#include<stdio.h>
#include<stdlib.h>

int n, n1, i;

struct node {
    int coef, ex, ey, ez;
    struct node *next;
};
struct node *newnode = NULL, *head = NULL, *temp = NULL;

struct node1 {
    int coef1, ex1, ey1, ez1;
    struct node1 *next1;
};
struct node1 *newnode1 = NULL, *head1 = NULL, *temp1 = NULL;

void create() {
    printf("Enter the number of terms(1): ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter coefficient: ");
        scanf("%d", &newnode->coef);
        printf("Enter exponent of x, y, z: ");
        scanf("%d%d%d", &newnode->ex, &newnode->ey, &newnode->ez);

        if(head == NULL) {
            head = newnode;
            newnode->next = NULL;
        }
        else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
        }
    }
}

void display() {
    temp = head;
    printf("Entered Polynomial is: ");
    while(temp != NULL) {
        printf("%dx^%dy^%dz^%d ", temp->coef, temp->ex, temp->ey, temp->ez);
        temp = temp->next;
        if (temp != NULL) {
            printf("+ ");
        }
    }
    printf("\nNumber of terms ----> %d\n\n", n);
}

void create2() {
    printf("Enter the number of terms(2): ");
    scanf("%d", &n1);
    for(i=0; i<n1; i++) {
        newnode1 = (struct node1*)malloc(sizeof(struct node1));
        printf("Enter coefficient: ");
        scanf("%d", &newnode1->coef1);
        printf("Enter exponent of x, y, z: ");
        scanf("%d%d%d", &newnode1->ex1, &newnode1->ey1, &newnode1->ez1);

        if(head1 == NULL) {
            head1 = newnode1;
            newnode1->next1 = NULL;
        }
        else {
            temp1 = head1;
            while(temp1->next1 != NULL) {
                temp1 = temp1->next1;
            }
            temp1->next1 = newnode1;
            newnode1->next1 = NULL;
        }
    }
}

void display2() {
    temp1 = head1;
    printf("Entered 2nd Polynomial is: ");
    while(temp1 != NULL) {
        printf("%dx^%dy^%dz^%d ", temp1->coef1, temp1->ex1, temp1->ey1, temp1->ez1);
        temp1 = temp1->next1;
        if (temp1 != NULL) {
            printf("+ ");
        }
    }
    printf("\nNumber of terms ----> %d\n\n", n1);
}

void add() {
    printf("Sum of polynomials is: ");
    display();
}

int main() {
    printf("Singly Linked List\n");
    create();
    display();
    printf("Now enter 2nd polynomial\n");
    create2();
    display2();
    add();
}
