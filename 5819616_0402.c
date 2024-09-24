#include <stdio.h>
#define MAX_TERMS 101

struct term {
    float coef;
    int expon;
} terms[MAX_TERMS] = {
    {7.0, 6}, {5.0, 3}, {9.0, 2}, {1.0, 0},
    {5.0, 3}, {2.0, 2}, {1.0, 1}, {10.0, 0}
};

int avail = 8;

void print_poly(int s, int e);
void poly_mult(int As, int Ae, int Bs, int Be, int* Cs, int* Ce);

int main(int argc, char* argv[]) {
    int As = 0, Ae = 3; // 다항식 A의 시작과 끝 인덱스
    int Bs = 4, Be = 7; // 다항식 B의 시작과 끝 인덱스
    int Cs, Ce; // C 다항식의 시작과 끝 인덱스

    poly_mult(As, Ae, Bs, Be, &Cs, &Ce); // 다항식 곱셈 실행
    print_poly(As, Ae); // 다항식 A 출력
    print_poly(Bs, Be); // 다항식 B 출력

    printf("----------------------------------\n");
    print_poly(Cs, Ce); // 다항식 C 출력

    return 0;
}

void poly_mult(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
    *Cs = avail;
    for (int i = As; i <= Ae; i++) {
        for (int j = Bs; j <= Be; j++) {
            int exp = terms[i].expon + terms[j].expon;
            float coef = terms[i].coef * terms[j].coef;
            int k;
            for (k = *Cs; k < avail; k++) {
                if (terms[k].expon == exp) {
                    terms[k].coef += coef;
                    break;
                }
            }
            if (k == avail) {
                terms[avail].expon = exp;
                terms[avail].coef = coef;
                avail++;
            }
        }
    }
    *Ce = avail - 1;
}

void print_poly(int s, int e) {
    // 마지막 항을 제외하고 모든 항 출력
    for (int i = s; i < e; i++) {
        if (i > s) printf(" + ");
        printf("%3.1fx^%d", terms[i].coef, terms[i].expon);
    }

    // 마지막 항이 상수항(지수가 0)인 경우, 상수만 출력
    if (terms[e].expon == 0) {
        printf(" + %3.1f", terms[e].coef); // 마지막 상수항 출력
    }
    else {
        // 마지막 항이 상수항이 아닌 경우, 일반적인 방식으로 출력
        printf(" + %3.1fx^%d", terms[e].coef, terms[e].expon);
    }

    printf("\n");
}
