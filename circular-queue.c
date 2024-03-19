/* Design ad implement a menu driven program in C for the following operations on circular queue of characters,
a) Insert an element on to circular queue
b) Delete an element fro circular queue
c) Demonstrate overflow and underflow situations on circular queue
d) Display the status of circular queue
*/



#include<stdio.h>
#define SIZE 4
int rear = -1, front = -1;
char queue[SIZE];
char item;

void insert() {
  if(front == ((rear + 1) % SIZE))
    printf("Queue is full.\n");
  else {
    rear = (rear + 1) % SIZE;
    printf("Enter item: ");
    scanf("%*c%c", &item);
    queue[rear] = item;
    printf("Item inserted: %c\n", item);
    if(front == -1) /* first element insertion into queue used for deletion */
      front++;
  }
}


void del() {
  if(front == -1)
    printf("Queue is empty.\n");
  else {
    item = queue[front];
    printf("Item delete: %c\n", item);
    if(front == rear)
      front = rear - 1;
    else
      front = (front + 1) % SIZE;
  }
}


void display() {
  int i, j;
  if(front == -1)
    printf("Queue is empty.\n");
  else {
    printf("Elements of queue are: \n");
    i = front;
    while(i != rear) {
      printf("%c ", queue[i]);
      i = (i + 1) % SIZE;
    }
    printf("%c\t", queue[i]);
    printf("\n");
  }
}


int main() {
  while(1) {
    int choice = 0; /* to select default option of switch when non-integer */
    printf("\nCircular Queue Operations\n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1: insert();
      break;
      case 2: del();
      break;
      case 3: display();
      break;
      case 4: return;
      default: printf("Invalid choice.\n");
      return;
    }
  }
}

/*

enqueue(conditions)
    (starting)       ->   if (front = -1)     -> make, front = 0
    (Full condition) ->   if (front = (rear+1)%size)   -> print, queue full

    (else) -> (increment rear) -> rear = (rear+1)%size
           -> (insert new item)-> queue[rear] = item


dequeue(conditions)
    (Empty condition)   ->   if(front = -1)   -> print, queue empty
    (else)   ->  if ->  (front == rear)   -> make, front = rear - 1
                 else   -> make, front = (front+1)%size


display(conditions)
    (Empty Condition)
    
    (else)    ->  make, i = front
              ->  while(i != rear)
                  ->(inside loop)   ->    print queue[i]
                                    ->    i = (i+1)%size (increment i)
                  ->(outside loop)  ->    print, queue[i]  (once)


*/