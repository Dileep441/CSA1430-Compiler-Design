#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_NON_TERMINALS 3
#define NUM_TERMINALS 5

// Define the non-terminals
enum NonTerminals { E, T, F };

// Define the terminals
enum Terminals { ID, PLUS, MULTIPLY, LEFT_PAREN, RIGHT_PAREN };

// Define the production rules for the grammar
char productions[NUM_NON_TERMINALS][10][10] = {
    { "T E'", "", "", "T E'", "", "" },
    { "F T'", "", "", "F T'", "", "" },
    { "id", "", "", "( E )", "", "" }
};

// Define the predictive parsing table
char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][20];

int main() {
    // Initialize the parsing table with empty strings
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        for (int j = 0; j < NUM_TERMINALS; j++) {
            strcpy(parsingTable[i][j], "");
        }
    }

    // Fill in the parsing table based on the production rules
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        for (int j = 0; j < NUM_TERMINALS; j++) {
            char *production = productions[i][j];
            if (strlen(production) > 0) {
                strcpy(parsingTable[i][j], production);
            }
        }
    }

    // Display the predictive parsing table
    printf("Predictive Parsing Table:\n");
    printf("       |  id  |  +  |  *  |  (  |  )  |\n");
    printf("------------------------------------\n");
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        switch (i) {
            case E:
                printf("   E   |");
                break;
            case T:
                printf("   T   |");
                break;
            case F:
                printf("   F   |");
                break;
        }
        for (int j = 0; j < NUM_TERMINALS; j++) {
            printf(" %4s |", parsingTable[i][j]);
        }
        printf("\n");
    }

    return 0;
}
