#include <stdio.h>
#include <string.h>

#define MAX_EXPR_LENGTH 100

struct Subexpression {
    char expression[MAX_EXPR_LENGTH];
    char result[MAX_EXPR_LENGTH];
    int used;
};

int main() {
    int n;
    printf("Enter the number of expressions: ");
    scanf("%d", &n);
    getchar(); // Consume the newline character

    struct Subexpression subexpressions[n];

    // Initialize subexpressions
    for (int i = 0; i < n; i++) {
        printf("Enter expression %d: ", i + 1);
        fgets(subexpressions[i].expression, MAX_EXPR_LENGTH, stdin);
        subexpressions[i].expression[strcspn(subexpressions[i].expression, "\n")] = '\0'; // Remove trailing newline
        subexpressions[i].used = 0;
    }

    printf("\nOptimized code:\n");

    // Print optimized code
    for (int i = 0; i < n; i++) {
        if (!subexpressions[i].used) {
            printf("%s\n", subexpressions[i].expression);
            subexpressions[i].used = 1;

            for (int j = i + 1; j < n; j++) {
                if (strcmp(subexpressions[i].expression, subexpressions[j].expression) == 0 && !subexpressions[j].used) {
                    subexpressions[j].used = 1;
                    printf("%s\n", subexpressions[j].result);
                }
            }
        }
    }

    return 0;
}
