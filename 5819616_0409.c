#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == (MAX_STACK_SIZE - 1));
}

void push(element item) {
    if (isFull()) {
        printf("Current rand_num : %d | Even\n", item);
        printf("Stack Overflow\n");
        return; // 여기서 함수를 종료합니다.
    }
    else {
        stack[++top] = item;
        printf("Current rand_num : %d | Even\n", item);
        printf("Push : %d\n", item);
    }
}

void pop(int rand_num) {
    if (isEmpty()) {
        printf("Current rand_num : %d | Odd\n", rand_num);
        printf("Stack Underflow\n");
    }
    else {
        printf("Current rand_num : %d | Odd\n", rand_num);
        printf("Pop : %d\n", stack[top--]);
    }
}

void print_stack() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
    }
    else {
        printf("Stack elements : ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1;
        if ((rand_num % 2) == 0) { // 짝수이면 push
            push(rand_num);
        }
        else { // 홀수이면 pop
            pop(rand_num);
        }
        print_stack(); // 매 반복마다 스택의 상태를 출력
        printf("\n"); // 명확한 구분을 위해 빈 줄 출력
    }
    return 0;
}
