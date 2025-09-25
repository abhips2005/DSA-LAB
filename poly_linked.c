#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;  
    int exp;    
    struct node* link; 
};

struct node* createNode(int coeff, int exp) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->link = NULL;
    return newNode;
}

void insertTerm(struct node** poly, int coeff, int exp) {
    struct node* newNode = createNode(coeff, exp);
    
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->link = *poly;
        *poly = newNode;
    } else {
        struct node* current = *poly;
        while (current->link != NULL && current->link->exp > exp) {
            current = current->link;
        }
        if (current->link != NULL && current->link->exp == exp) {
            current->link->coeff += coeff;
            free(newNode); 
        } else {
            newNode->link = current->link;
            current->link = newNode;
        }}}
void displayPolynomial(struct node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->link;
        if (poly != NULL && poly->coeff > 0) {
            printf(" + ");
        }
    }
    printf("\n");
}
struct node* addPolynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {  
                insertTerm(&result, sumCoeff, poly1->exp);
            }
            poly1 = poly1->link;
            poly2 = poly2->link;
        } else if (poly1->exp > poly2->exp) {
            
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->link;
        } else {
            
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->link;
        }
    }
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->link;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->link;
    }
    return result;
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;

    int coeff, exp;
    int n1, n2;
    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter the terms (coefficient and exponent) for Polynomial 1:\n");
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }
    printf("Enter the number of terms for Polynomial 2: ");
    scanf("%d", &n2);
    printf("Enter the terms (coefficient and exponent) for Polynomial 2:\n");
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    struct node* result = addPolynomials(poly1, poly2);
    printf("Result of addition: ");
    displayPolynomial(result);

    return 0;
}

