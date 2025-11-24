#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 스택을 위한 노드 포인터 배열
#define MAX_SIZE 100
Node* stack[MAX_SIZE];
int top = -1;

// 스택 연산
void push(Node* node) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = node;
    }
}

Node* pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return NULL;
}

// reverse 함수 (스택 사용)
void reverse(Node** head) {
    Node* current = *head;

    // 스택에 노드들을 모두 push
    while (current != NULL) {
        push(current);
        current = current->next;
    }

    // 스택에서 pop 하면서 리스트 재구성
    if (top == -1) return;  // 빈 리스트 처리
    *head = pop();
    current = *head;

    while (top >= 0) {
        current->next = pop();
        current = current->next;
    }

    current->next = NULL;  // 마지막 노드의 next는 NULL
}

// 유틸: 리스트 출력
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// 유틸: 노드 생성
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 테스트
int main() {
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Original list: ");
    printList(head);

    reverse(&head);

    printf("Reverse list: ");
    printList(head);

    return 0;
}