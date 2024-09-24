#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void menu() {
    printf("\n메뉴 : \n");
    printf("1: 숫자 입력 받아서 리스트 처음에 추가\n");
    printf("2: 숫자 입력 받아서 리스트 마지막에 추가\n");
    printf("3: 리스트 처음 노드 삭제\n");
    printf("4: 리스트 마지막 노드 삭제\n");
    printf("5: 리스트 프린트\n");
    printf("6: 종료\n");
}

ListNode* insert_first(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;

    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

ListNode* delete_first(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* temp = head->link;
    if (head == temp) { 
        free(head);
        return NULL;
    }
    head->link = temp->link;
    free(temp);
    return head;
}

ListNode* delete_last(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* prev = head;
    ListNode* temp = head->link;

    if (prev == temp) { 
        free(head);
        return NULL;
    }

    while (temp->link != head->link) {
        prev = temp;
        temp = temp->link;
    }
    prev->link = head->link;
    free(temp);
    return prev;
}

void print_list(ListNode* head) {
    if (head == NULL) return;
    ListNode* p = head->link;
    do {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != head);
    printf("%d (head)\n", p->data);
}

int main() {
    int choice;
    int data;
    ListNode* head = NULL;

    while (1) {
        menu();
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 숫자를 입력하세요: ");
            scanf("%d", &data);
            head = insert_first(head, data);
            break;
        case 2:
            printf("추가할 숫자를 입력하세요: ");
            scanf("%d", &data);
            head = insert_last(head, data);
            break;
        case 3:
            head = delete_first(head);
            break;
        case 4:
            head = delete_last(head);
            break;
        case 5:
            print_list(head);
            break;
        case 6:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
            break;
        }
    }
}
