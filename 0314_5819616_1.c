#include <stdio.h>
#include <time.h>

int main() {
    int start, stop; //clock 함수 호출
    double duration; //시간 계산 변수
    start = clock(); // 시간 측정 시작

    int sum = 0, num, isPrime;

    // 0부터 100까지 소수의 합 구하기
    for (num = 2; num <= 100; num++) {
        isPrime = 1; // 우선 소수라고 가정
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0; // 소수가 아님
                break;
            }
        }
        if (isPrime) {
            sum += num; //소수면 더하기
        }
    }

    stop = clock(); // 시간 측정 종료
    duration = (double)(stop - start) / CLOCKS_PER_SEC; // 실행 시간 계산

    printf("시간 : %f s\n", duration); //소수의 합 출력
    printf("소수의 합 : %d", sum); //시간 출력

    return 0;
}