#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top < SIZE - 1) stack[++top] = c;
}

char pop(void) {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek(void) {
    if (top == -1) return '\0';
    return stack[top];
}

/* precedence: higher number -> higher precedence */
int precedence(char symbol) {
    if (symbol == '^') return 3;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return 0;
}

void infixToPostfix(const char *infix, char *postfix) {
    int i = 0, k = 0;
    top = -1;               // reset stack
    push('(');              // push '(' as sentinel
    int len = strlen(infix);
    // append ')' at end logically by treating end as ')'
    for (i = 0; i < len; ++i) {
        char ch = infix[i];
        if (ch == ' ' || ch == '\t') continue; // ignore spaces

        if (isalnum((unsigned char)ch)) {
            postfix[k++] = ch;       // operand -> output
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '\0' && peek() != '(') {
                postfix[k++] = pop();
            }
            if (peek() == '(') pop(); // pop '('
        } else { // operator
            while (peek() != '\0' && precedence(peek()) >= precedence(ch)) {
                // '^' is usually right-associative; if you want '^' right-assoc:
                // break when peek() == '^' and ch == '^'
                if (peek() == '^' && ch == '^') break; // right-assoc for '^'
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // pop remaining operators until '(' sentinel (if any)
    while (peek() != '\0' && peek() != '(') {
        postfix[k++] = pop();
    }
    if (peek() == '(') pop();

    postfix[k] = '\0';
}

int main(void) {
    char infix[SIZE], postfix[SIZE];

    printf("Enter infix expression (single-char operands):\n");
    if (!fgets(infix, sizeof(infix), stdin)) return 0;
    // remove trailing newline if present
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') infix[len - 1] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
