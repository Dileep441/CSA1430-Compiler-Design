#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the grammar productions
const char* productions[] = {
    "E->E+T",
    "E->T",
    "T->T*F",
    "T->F",
    "F->(E)",
    "F->id"
};

// Define the SLR parsing table
char parsing_table[6][7] = {
    { 'S', ' ', ' ', 'S', ' ', ' ', ' ' },
    { ' ', 'S', ' ', ' ', ' ', ' ', 'A' },
    { ' ', 'R', 'S', 'R', 'R', ' ', 'R' },
    { ' ', 'R', 'R', 'R', 'R', ' ', 'R' },
    { 'S', ' ', ' ', 'S', ' ', ' ', ' ' },
    { ' ', 'R', 'R', 'R', 'R', ' ', 'R' }
};

// Define a stack to perform parsing
char stack[100];
int top = -1;

// Helper function to perform reduction
void reduce(int production_index) {
    char production[5];
    int len = strlen(productions[production_index]);

    for (int i = 3; i < len; i++) {
        production[i - 3] = productions[production_index][i];
    }

    production[len - 3] = '\0';

    top -= len - 3;

    stack[++top] = productions[production_index][0];

    int row = stack[top - 1] - 'E';
    int col = stack[top] - 'E';

    stack[++top] = parsing_table[row][col];
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    strcat(input, "$"); // Add end marker

    stack[++top] = '0';

    int i = 0;

    while (1) {
        int row = stack[top] - '0';
        int col;

        for (col = 0; col < 7; col++) {
            if (input[i] == parsing_table[0][col]) {
                break;
            }
        }

        if (parsing_table[row][col] == 'A') {
            printf("Accepted\n");
            break;
        } else if (parsing_table[row][col] == 'S') {
            stack[++top] = input[i++];
            stack[++top] = parsing_table[row][col];
        } else if (parsing_table[row][col] == 'R') {
            int production_index = col;
            reduce(production_index);
        } else {
            printf("Error: Invalid input\n");
            break;
        }
    }

    return 0;
}
