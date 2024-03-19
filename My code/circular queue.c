//  Circular Queue

/*
    insert alli full check (front == (rear+1)%SIZE), illandre (rear+1)%SIZE madi, insert rear (remember else alli, front == -1 agidre front = 0 madu)

    delete alli empty unta nodu (front == -1), illandre front annu item ge haki print madu mathe front annu increment madu (front = (front+1)%SIZE)
                (remember delete idu else alli front == 0 mathe rear == SIZE-1 agidre yeradannu -1 madu)

    display alli empty unta nodu illandre i = front madi while loop barilike
*/

#include<stdio.h>
#define SIZE 4

int front = -1, rear = -1, i, choice;
char item, a[SIZE];

void insert() {
    if(front == (rear+1)%SIZE) {
        printf("Queue is full\n");
    }
    else {
        printf("Enter the item: ");
        scanf(" %c", &item);
        rear = (rear+1)%SIZE;
        a[rear] = item;
        if(front == -1) {
            front = 0;
        }
    }
}

void delete() {
    if(front == -1) {
        printf("Queue is empty\n");
    }
    else {
        item = a[front];
        printf("Deleted item is: %c", item);
        front = (front+1)%SIZE;
        if(front == 0 && rear == SIZE - 1) {
            rear = -1;
            front = -1;
            printf("Queue is empty\n");
        }
    }
}

void display() {
    if(front == -1) {
        printf("Queue is empty\n");
    }
    else {
        i = front;
        printf("Items in the queue: \n");
        while(i != rear) {
            printf("%c\t", a[i]);
            i = (i+1)%SIZE;
        }
        printf("%c\n", a[i]);
    }
}

int main() {
    printf("Circular Queue Operations: \n");
    while(1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. EXIT\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insert();
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            case 4: return 0;
            default: printf("Invalid choice\n");
            return 0;
        }
    }
}