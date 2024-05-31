#include <stdio.h>
#include <string.h>
#include <ctype.h>

int evaluate(int a, int b, char op) {
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    
    default:
        break;
    }
}

/* convert a char to int */
int charToInt(char c) {
    return c - '0';
}

/* checks if char is an operator */
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int isSpace(char c) {
    return c == ' ';
}

/* checks if string is a valid expression */
int isValid(char* expression) {
    if (isdigit(expression[0]) && 
        isSpace(expression[1]) &&
        isOperator(expression[2]) &&
        isSpace(expression[3]) &&
        isdigit(expression[4])) return 1;
    return 0;
}

void calc() {
    
    /* a string to store input */
    char expression[11];
    char output[100][11];
    int counter = 0;

    while (1) {
        
        /* get a string from user */
        fgets(expression, sizeof(expression), stdin);
        expression[strcspn(expression, "\n")] = '\0';
        if (strcmp(expression, "exit") == 0) break;

        /* if expression is valid - calculate and store in output array */
        if (isValid(expression)) {            
            int a = charToInt(expression[0]);
            int b = charToInt(expression[4]);
            char op = expression[2];
            int result = evaluate(a, b, op);
            sprintf(output[counter], "%d", result);
            counter++;
        }
        
        /* if expression isnt valid - store the expression in output array */
        else {
            strcpy(output[counter], expression);
            counter++;
        }
    }

    for (int i = 0; i < counter; i++) {
        printf("%s\n", output[i]);
    }

    return;
}


int main() {

    calc();
    return 1;
}
