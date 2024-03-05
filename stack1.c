/*
2. Design and Implement a program in C for the following Stack Applications,
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^
*/
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int Stack[50], top = -1;

// PUSH function
void push(int elem) {
    Stack[++top] = elem;
}

// main() function
int main() {
    char postfix[50], ch;
    int i = 0, op1, op2;
    printf("Enter a postfix expression with single digit operands and operators: ");
    scanf("%s", postfix);

    while ((ch = postfix[i++]) != '\0') {
        if (isalpha(ch)) {
            printf("Invalid Expression\n");
            return 1; // Exit with an error code
        } else if (isdigit(ch)) {
            push(ch - '0'); // Convert character to integer
        } else {
            op2 = Stack[top--];
            if (top < 0) {
                printf("Invalid expression\n");
                return 1; // Exit with an error code
            }
            op1 = Stack[top--];
            switch (ch) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '%':
                    push(op1 % op2);
                    break;
                case '^':
                    push(pow(op1, op2));
                    break;
                default:
                    printf("Invalid Operator\n");
                    return 1; // Exit with an error code
            }
        }
    }
    if (top != 0) {
        printf("Invalid expression\n");
        return 1; // Exit with an error code
    } else {
        printf("Result = %d\n", Stack[top]);
        return 0; // Exit successfully
    }
}