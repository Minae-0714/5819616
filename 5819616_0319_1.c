#include <stdio.h>
#include <time.h>

long factorial_iter(int n) {
    long result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

long factorial_rec(int n, int k) {
    if (n <= 1) {
        return 1;
    }
    else {
        long result = n * factorial_rec(n - 1, 0);
        if (k == 1)
        return result;
    }
}

int main() {
    clock_t start, end;
    double time_iter, time_rec;
    long result_iter, result_rec;

    // 반복적 방법으로 팩토리얼 계산
    start = clock();
    result_iter = factorial_iter(20);
    end = clock();
    time_iter = ((double)(end - start)) / CLOCKS_PER_SEC;

    // 재귀적 방법으로 팩토리얼 계산
    start = clock();
    result_rec = factorial_rec(20, 1);
    end = clock();
    time_rec = ((double)(end - start)) / CLOCKS_PER_SEC;

    // 결과 출력
    printf("Factorial Iterative Result : %ld\n", result_iter);
    printf("time (iterative) : %f seconds\n", time_iter);
    printf("Factorial Recursive Result : %ld\n", result_rec);
    printf("time (recursive) : %f seconds\n", time_rec);

    return 0;
}
