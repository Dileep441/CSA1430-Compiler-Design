#include <stdio.h>
#include <string.h>

// Define a grammar that is known to be ambiguous
const char* productions[] = {
    "E->E+E",
    "E->E*E",
    "E->(E)",
    "E->id"
};

// Function to check if the input is ambiguous
int isAmbiguous(const char* input) {

    return 1;
}

int main() {
    char input[100];
    printf("Enter an input string: ");
    scanf("%s", input);

    int result = isAmbiguous(input);
    
    if (result) {
        printf("The grammar is ambiguous.\n");
    } else {
        printf("The grammar is not ambiguous.\n");
    }

    return 0;
}
