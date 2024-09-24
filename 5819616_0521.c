#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_FRUIT_NAME 50

typedef char element[MAX_FRUIT_NAME];

typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} DeletedListType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
}

void init(ArrayListType* L) {
    L->size = 0;
}

void init_deleted(DeletedListType* L) {
    L->size = 0;
}

int is_full(ArrayListType* L) {
    return L->size == MAX_LIST_SIZE;
}

void add_fruit(ArrayListType* L, char* fruit) {
    if (is_full(L)) {
        error("List Overflow");
        return;
    }
    for (int i = 0; i < L->size; i++) {
        if (strcmp(L->array[i], fruit) == 0) {
            printf("이미 존재하는 과일입니다.\n");
            return;
        }
    }
    strcpy(L->array[L->size++], fruit);
    printf("추가 완료\n");
}

void delete_fruit(ArrayListType* L, DeletedListType* D, char* fruit) {
    int found = 0;
    for (int i = 0; i < L->size; i++) {
        if (strcmp(L->array[i], fruit) == 0) {
            found = 1;
            strcpy(D->array[D->size++], fruit);
            for (int j = i; j < L->size - 1; j++) {
                strcpy(L->array[j], L->array[j + 1]);
            }
            L->size--;
            printf("삭제 완료\n");
            break;
        }
    }
    if (!found) {
        printf("해당 과일이 없습니다.\n");
    }
}

void print_deleted(DeletedListType* D) {
    if (D->size == 0) {
        printf("삭제된 과일이 없습니다.\n");
        return;
    }
    printf("삭제된 과일 목록:\n");
    for (int i = 0; i < D->size; i++) {
        printf("%s\n", D->array[i]);
    }
}

int main() {
    ArrayListType list;
    DeletedListType deleted_list;
    init(&list);
    init_deleted(&deleted_list);

    // 초기 과일 리스트
    char* initial_fruits[] = { "Mango", "Orange", "Apple", "Grape", "Cherry", "Plum", "Guava", "Raspberry", "Banana", "Peach" };
    for (int i = 0; i < 10; i++) {
        add_fruit(&list, initial_fruits[i]);
    }

    int choice;
    char fruit[MAX_FRUIT_NAME];

    while (1) {
        printf("\n메뉴 : \n");
        printf("1. 리스트에 새로운 과일 추가\n");
        printf("2. 리스트에서 과일 삭제\n");
        printf("3. 삭제된 과일 목록 출력\n");
        printf("4. 프로그램 종료\n");
        printf("선택 : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 과일 이름을 입력하세요 : ");
            scanf("%s", fruit);
            add_fruit(&list, fruit);
            break;
        case 2:
            printf("삭제할 과일 이름을 입력하세요 : ");
            scanf("%s", fruit);
            delete_fruit(&list, &deleted_list, fruit);
            break;
        case 3:
            print_deleted(&deleted_list);
            break;
        case 4:
            printf("프로그램 종료\n");
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 시도하세요\n");
        }
    }
}
