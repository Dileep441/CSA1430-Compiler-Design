#include <stdio.h>
#include <string.h>

int main() {
    char grammar[100], nonTerminal, productions[50][50];
    int numProductions;

    printf("Enter the production (e.g., E->Ea|Eb|Fc): ");
    scanf("%s", grammar);

    // Parse the grammar input
    char* arrow = strchr(grammar, '-');
    if (arrow == NULL || arrow[1] != '>') {
        printf("Invalid input format.\n");
        return 1;
    }

    nonTerminal = grammar[0];
    arrow += 2;

    char* production = strtok(arrow, "|");
    numProductions = 0;
    while (production != NULL) {
        strcpy(productions[numProductions], production);
        numProductions++;
        production = strtok(NULL, "|");
    }

    // Eliminate left factoring
    char commonPrefix[50] = "";
    int prefixLength = 0;

    // Find the common prefix among productions
    for (int i = 0; i < numProductions - 1; i++) {
        for (int j = i + 1; j < numProductions; j++) {
            int k = 0;
            while (productions[i][k] != '\0' && productions[j][k] != '\0' && productions[i][k] == productions[j][k]) {
                commonPrefix[k] = productions[i][k];
                k++;
            }
            commonPrefix[k] = '\0';

            if (k > 0 && k > prefixLength) {
                prefixLength = k;
            }
        }
    }

    // Print the modified productions
    if (prefixLength > 0) {
        printf("Modified grammar after left factoring:\n");
        printf("%c -> %s%s'\n", nonTerminal, commonPrefix, nonTerminal);
        printf("%c' -> %s\n", nonTerminal, productions[0] + prefixLength);
        for (int i = 1; i < numProductions; i++) {
            if (strncmp(productions[i], commonPrefix, prefixLength) == 0) {
                printf("%c' -> %s\n", nonTerminal, productions[i] + prefixLength);
            } else {
                printf("%c' -> %s\n", nonTerminal, productions[i]);
            }
        }
    } else {
        printf("No left factoring found in the grammar.\n");
    }

    return 0;
}
