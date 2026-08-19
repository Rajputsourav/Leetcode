#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {

        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {

            int b = stack[top--];
            int a = stack[top--];

            if (strcmp(tokens[i], "+") == 0)
                stack[++top] = a + b;
            else if (strcmp(tokens[i], "-") == 0)
                stack[++top] = a - b;
            else if (strcmp(tokens[i], "*") == 0)
                stack[++top] = a * b;
            else
                stack[++top] = a / b;
        }
        else {
    
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}