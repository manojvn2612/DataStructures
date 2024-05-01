/*
Manoj Nayak
Panel C Roll no. 17
*/
#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

void addToPolynomial(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);

    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            addToPolynomial(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            addToPolynomial(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else {
            if (poly1->exponent > poly2->exponent) {
                addToPolynomial(&result, poly1->coefficient, poly1->exponent);
                poly1 = poly1->next;
            } else if (poly1->exponent < poly2->exponent) {
                addToPolynomial(&result, poly2->coefficient, poly2->exponent);
                poly2 = poly2->next;
            } else {
                int sumCoeff = poly1->coefficient + poly2->coefficient;
                addToPolynomial(&result, sumCoeff, poly1->exponent);
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
    }

    return result;
}


void displayPolynomial(struct Term* poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    addToPolynomial(&poly1, 3, 2);
    addToPolynomial(&poly1, 2, 1);
    addToPolynomial(&poly1, 5, 0);

    addToPolynomial(&poly2, 4, 3);
    addToPolynomial(&poly2, 1, 2);
    addToPolynomial(&poly2, 2, 0);

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    struct Term* result = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    displayPolynomial(result);

    return 0;
}
