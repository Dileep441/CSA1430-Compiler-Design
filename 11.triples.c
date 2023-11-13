#include <stdio.h>
#include <string.h>

#define MAX_TRIPLES 100

struct Triple {
    char operator[10];
    char source1[10];
    char source2[10];
    char target[10];
};

int tripleIndex = 0;
struct Triple triples[MAX_TRIPLES];

void addTriple(const char* op, const char* src1, const char* src2, const char* tgt) {
    if (tripleIndex < MAX_TRIPLES) {
        strcpy(triples[tripleIndex].operator, op);
        strcpy(triples[tripleIndex].source1, src1);
        strcpy(triples[tripleIndex].source2, src2);
        strcpy(triples[tripleIndex].target, tgt);
        tripleIndex++;
    } else {
        printf("Max triples exceeded\n");
    }
}

void printTriples() {
    printf("\nGenerated Triples:\n");
    for (int i = 0; i < tripleIndex; i++) {
        printf("(%s, %s, %s, %s)\n", triples[i].operator, triples[i].source1, triples[i].source2, triples[i].target);
    }
}

int main() {
    // Generate triples for a simple expression: a = b + c * d
    addTriple("MULT", "c", "d", "t1");
    addTriple("ADD", "b", "t1", "t2");
    addTriple("ASSIGN", "t2", "", "a");

    // Generate triples for another expression: e = f * g
    addTriple("MULT", "f", "g", "t3");
    addTriple("ASSIGN", "t3", "", "e");

    // Print the generated triples
    printTriples();

    return 0;
}
