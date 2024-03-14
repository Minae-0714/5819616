#include <stdio.h>
#include <time.h>

int main() {
    int start, stop; //clock �Լ� ȣ��
    double duration; //�ð� ��� ����
    start = clock(); // �ð� ���� ����

    int sum = 0, num, isPrime;

    // 0���� 100���� �Ҽ��� �� ���ϱ�
    for (num = 2; num <= 100; num++) {
        isPrime = 1; // �켱 �Ҽ���� ����
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0; // �Ҽ��� �ƴ�
                break;
            }
        }
        if (isPrime) {
            sum += num; //�Ҽ��� ���ϱ�
        }
    }

    stop = clock(); // �ð� ���� ����
    duration = (double)(stop - start) / CLOCKS_PER_SEC; // ���� �ð� ���

    printf("�ð� : %f s\n", duration); //�Ҽ��� �� ���
    printf("�Ҽ��� �� : %d", sum); //�ð� ���

    return 0;
}