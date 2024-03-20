#include <stdio.h>
#include <time.h>

double power_iter(int base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

double power_rec(int base, int exponent) {
    if (exponent == 0)
        return 1.0;
    else if (exponent % 2 == 0) {
        double half_power = power_rec(base, exponent / 2);
        return half_power * half_power;
    }
    else {
        double half_power = power_rec(base, (exponent - 1) / 2);
        return base * half_power * half_power;
    }
}

int main() {
    clock_t start, end;
    double time_iter, time_rec;
    double result_iter, result_rec;

    // 반복적 방법으로 거듭제곱 계산
    start = clock();
    result_iter = power_iter(13, 21);
    end = clock();
    time_iter = ((double)(end - start)) / CLOCKS_PER_SEC;

    // 재귀적 방법으로 거듭제곱 계산
    start = clock();
    result_rec = power_rec(13, 21);
    end = clock();
    time_rec = ((double)(end - start)) / CLOCKS_PER_SEC;

    // 결과 출력
    printf("Power Iterative Result : %.0lf\n", result_iter);
    printf("Time (iterative) : %.6f seconds\n", time_iter);
    printf("Power Recursive Result : %.0lf\n", result_rec);
    printf("Time (recursive) : %.6f seconds\n", time_rec);

    return 0;
}
