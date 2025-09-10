#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>// For atoi
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
}

void infixtopostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;

    while ((c = infix[i]) != '\0') {
        if (isalnum(c)) {  // If it's an operand (variable or digit)
            postfix[j++] = c;
        } else if (c == '(') {  // Left parenthesis
            push(c);
        } else if (c == ')') {  // Right parenthesis
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();  // Discard the '('
        } else if (isOperator(c)) {  // If it's an operator
            while (top != -1 && isOperator(peek()) && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

int evaluatePostfix(char postfix[]) {
    int i = 0;
    int operand1, operand2, result;
    char c;

    top = -1;  // Reset stack for evaluation

    while ((c = postfix[i]) != '\0') {
        if (isdigit(c)) {  // If it's an operand (digit)
            push(c - '0');  // Convert char to integer
        } else if (isOperator(c)) {  // If it's an operator
            operand2 = pop();
            operand1 = pop();

            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = 1;
                    for (int j = 0; j < operand2; j++) {
                        result *= operand1;
                    }
                    break;
                default:
                    printf("Invalid operator encountered.\n");
                    return -1;
            }

            push(result);  // Push the result of the operation back onto the stack
        }
        i++;
    }

    return pop();  // The final result will be the only value left in the stack
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression: ");
   
    // Use fgets to read the full expression including spaces
    fgets(infix, MAX, stdin);
   
    // Remove the newline character at the end of the input, if present
    infix[strcspn(infix, "\n")] = '\0';
   
    // Convert infix to postfix
    infixtopostfix(infix, postfix);
    printf("The postfix expression is: %s\n", postfix);
   
    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    printf("The result of the postfix evaluation is: %d\n", result);
   
    return 0;
}