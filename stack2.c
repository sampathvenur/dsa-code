// b) Conversion of Arithmetic expression


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20
char stack[SIZE];
int top = -1;

void push(char elem) {
  stack[++top] = elem;
}

char pop() {
  return(stack[top--]);
}

int precedence(char elem) /* Decides the precedence */ {
  switch(elem) {
    case '#': return 0;
    case '(': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/':
    case '%': return 3;
    case '^': return 4;
    default: printf("Not a valid expression\n");
    exit(0);
  }
}


void main() {
  char infix[20], postfix[20], ch, elem;
  int i = 0, k = 0, pr;
  printf("Enter the infix expression: ");
  scanf("%s", infix);
  push('#'); /* Initial element of stack. It is a handler */

  while((ch = infix[i++]) != '\0') {
    if(ch == '(') /* verifying left paranthesis */
      push(ch);
    else if(isalnum(ch)) /* verifying operand */
      postfix[k++] = ch;
    else if(ch == ')')  /* verifying right paranthesis*/ {
      while(stack[top] != '(') {
        postfix[k++] = pop();
        if(stack[top] == '#') {
          printf("Not a vaid expression\n");
          exit(0);
        }
      }
      elem = pop(); /* removing left paranthesis */
    }
    else {
      pr = precedence(ch);
      if(ch == '^') {
        pr++; /* If ^ appears more than once avaluation takes place from right to left */
      }
      while(precedence(stack[top]) >= pr) {
        postfix[k++] = pop();
      }
      push(ch); /* Push the operator to stack */
    }
  }
  while(stack[top] != '#')  /* Pop from stack till empty */ {
    postfix[k++] = pop();
  }
  postfix[k] = '\0';  /* Make postfix as valid string*/
  printf("Given infix expression: %s\nThe postfix expression is: %s\n", infix, postfix);
}
