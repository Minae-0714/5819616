#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
    if (phead->rlink == phead) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    DListNode* p = phead->rlink;
    while (p != phead) {
        printf("%d", p->data);
        if (p->rlink != phead) {
            printf(" -> ");
        }
        p = p->rlink;
    }
    printf(" (head)\n");
}


void add_first(DListNode* phead, element data) {
    DListNode* new_node = (DListNode*)malloc(sizeof(DListNode));
    new_node->data = data;
    new_node->rlink = phead->rlink;
    new_node->llink = phead;
    phead->rlink->llink = new_node;
    phead->rlink = new_node;
}

void add_last(DListNode* phead, element data) {
    DListNode* new_node = (DListNode*)malloc(sizeof(DListNode));
    new_node->data = data;
    new_node->llink = phead->llink;
    new_node->rlink = phead;
    phead->llink->rlink = new_node;
    phead->llink = new_node;
}

void delete_first(DListNode* phead) {
    if (phead->rlink == phead) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    DListNode* removed_node = phead->rlink;
    phead->rlink = removed_node->rlink;
    removed_node->rlink->llink = phead;
    free(removed_node);
}

void delete_last(DListNode* phead) {
    if (phead->llink == phead) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    DListNode* removed_node = phead->llink;
    phead->llink = removed_node->llink;
    removed_node->llink->rlink = phead;
    free(removed_node);
}

int main() {
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    int choice, data;

    while (1) {
        printf("\n메뉴\n");
        printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
        printf("2: 숫자 입력 받아서 리스트 마지막에 추가\n");
        printf("3: 리스트 처음 노드 삭제\n");
        printf("4: 리스트 마지막 노드 삭제\n");
        printf("5: 리스트 프린트\n");
        printf("6: 종료\n");
        printf("선택 : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 숫자를 입력하세요: ");
            scanf("%d", &data);
            add_first(head, data);
            break;
        case 2:
            printf("추가할 숫자를 입력하세요: ");
            scanf("%d", &data);
            add_last(head, data);
            break;
        case 3:
            delete_first(head);
            break;
        case 4:
            delete_last(head);
            break;
        case 5:
            print_dlist(head);
            break;
        case 6:
            printf("프로그램 종료\n");
            exit(0);
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
            break;
        }
    }
    return 0;
}
