#include <stdio.h>
#include <string.h>

#define MAX_CODE_LINES 100
#define MAX_LINE_LENGTH 100

int main() {
    int numLines;
    printf("Enter the number of lines of code: ");
    scanf("%d", &numLines);
    getchar(); // Consume the newline character

    char code[MAX_CODE_LINES][MAX_LINE_LENGTH];
    int isLive[MAX_CODE_LINES] = {0};

    // Input code lines
    for (int i = 0; i < numLines; i++) {
        printf("Enter code line %d: ", i + 1);
        fgets(code[i], MAX_LINE_LENGTH, stdin);
        code[i][strcspn(code[i], "\n")] = '\0'; // Remove trailing newline
    }

    // Input live variables
    int numLiveVars;
    printf("\nEnter the number of live variables: ");
    scanf("%d", &numLiveVars);
    getchar(); // Consume the newline character

    char liveVars[numLiveVars][MAX_LINE_LENGTH];

    for (int i = 0; i < numLiveVars; i++) {
        printf("Enter live variable %d: ", i + 1);
        fgets(liveVars[i], MAX_LINE_LENGTH, stdin);
        liveVars[i][strcspn(liveVars[i], "\n")] = '\0'; // Remove trailing newline
    }

    // Mark lines with live variables as live
    for (int i = 0; i < numLines; i++) {
        for (int j = 0; j < numLiveVars; j++) {
            if (strstr(code[i], liveVars[j]) != NULL) {
                isLive[i] = 1;
                break;
            }
        }
    }

    // Print optimized code
    printf("\nOptimized code (dead code eliminated):\n");
    for (int i = 0; i < numLines; i++) {
        if (isLive[i]) {
            printf("%s\n", code[i]);
        }
    }

    return 0;
}
