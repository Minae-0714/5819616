#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

void print_poly(polynomial p) {
    for (int i = p.degree; i > 0; i--) {
        printf("%3.1f X ^%d + ", p.coef[p.degree - i], i);
    }
    printf("%3.1f \n", p.coef[p.degree]);
}

polynomial poly_mult(polynomial a, polynomial b) {
    polynomial result;
    result.degree = a.degree + b.degree;
    for (int i = 0; i <= result.degree; i++) result.coef[i] = 0;

    for (int i = 0; i <= a.degree; i++) {
        for (int j = 0; j <= b.degree; j++) {
            result.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }
    return result;
}

int main(void) {
    polynomial c;

    polynomial a = { 6, {7, 0, 0, 5, 9, 0, 1} };
    polynomial b = { 3, {5, 2, 1, 10} };

    print_poly(a);
    print_poly(b);

    c = poly_mult(a, b);
    printf("---------------------------\n");
    print_poly(c);

    return 0;
}
