#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

// 단순 연결 리스트 초기화
ListNode* init() {
    return NULL;
}

// 단순 연결 리스트 삽입
ListNode* insert(ListNode* head, int pos, element item, int* move_count) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* p = head;
    *move_count = 1;

    node->data = item;
    node->link = NULL;

    if (pos == 0) { // 처음 위치에 삽입
        node->link = head;
        head = node;
    }
    else {
        ListNode* prev = NULL;
        for (int i = 0; i < pos && p != NULL; i++) {
            prev = p;
            p = p->link;
            (*move_count)++;
        }
        if (p == NULL && prev == NULL) { // 위치가 리스트 크기보다 크고, 리스트가 비어있는 경우
            free(node);
            *move_count = -1;
            return head;
        }
        node->link = p;
        if (prev != NULL) {
            prev->link = node;
        }
    }
    return head;
}

// 단순 연결 리스트 삭제
ListNode* delete(ListNode* head, int pos, int* move_count) {
    ListNode* p = head;
    ListNode* prev = NULL;
    *move_count = 1;

    if (pos == 0 && head != NULL) { // 첫 번째 노드 삭제
        head = head->link;
        free(p);
    }
    else {
        while (pos > 0 && p != NULL) {
            prev = p;
            p = p->link;
            pos--;
            (*move_count)++;
        }
        if (prev != NULL && p != NULL) {
            prev->link = p->link;
            free(p);
        }
    }
    return head;
}

// 단순 연결 리스트 출력
void print_list(ListNode* head) {
    ListNode* p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

int main() {
    ListNode* list = init();
    int choice, pos, move_count;
    element item;

    while (1) {
        printf("\n메뉴 : \n");
        printf("1. 리스트에 숫자 추가\n");
        printf("2. 리스트에서 숫자 삭제\n");
        printf("3. 리스트 출력\n");
        printf("0. 프로그램 종료\n");
        printf("선택 : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 숫자를 입력하세요 : ");
            scanf("%d", &item);
            printf("추가할 위치를 입력하세요 : ");
            scanf("%d", &pos);
            list = insert(list, pos, item, &move_count);
            printf("삽입 완료, 링크를 따라 이동한 횟수 : %d\n", move_count);
            break;
        case 2:
            printf("삭제할 위치를 입력하세요 : ");
            scanf("%d", &pos);
            list = delete(list, pos, &move_count);
            printf("삭제 완료, 링크를 따라 이동한 횟수 : %d\n", move_count);
            break;
        case 3:
            print_list(list);
            break;
        case 0:
            printf("프로그램 종료\n");
            // 메모리 해제
            while (list != NULL) {
                ListNode* tmp = list;
                list = list->link;
                free(tmp);
            }
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 시도하세요\n");
        }
    }
}
