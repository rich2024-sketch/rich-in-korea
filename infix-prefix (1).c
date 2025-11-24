#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// 노드 구조체 정의
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// 연산자 스택 정의
#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;

// 스택 연산
void push(char c) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

// 연산자 우선순위
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // for '('
}

// 중위 → 후위 함수 (linked list 사용)
Node* infixToPostfix(Node* head) {
    Node* resultHead = NULL;
    Node* resultTail = NULL;

    Node* current = head;
    while (current != NULL) {
        char ch = current->data;

        if (isalnum(ch)) {
            // 피연산자 → 바로 결과 리스트에 추가
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = ch;
            newNode->next = NULL;

            if (resultHead == NULL) {
                resultHead = resultTail = newNode;
            }
            else {
                resultTail->next = newNode;
                resultTail = newNode;
            }
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(') {
                char op = pop();
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->data = op;
                newNode->next = NULL;
                resultTail->next = newNode;
                resultTail = newNode;
            }
            pop(); // '(' 버리기
        }
        else {
            while (precedence(peek()) >= precedence(ch)) {
                char op = pop();
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->data = op;
                newNode->next = NULL;
                if (resultTail == NULL) {
                    resultHead = resultTail = newNode;
                }
                else {
                    resultTail->next = newNode;
                    resultTail = newNode;
                }
            }
            push(ch);
        }

        current = current->next;
    }

    while (top != -1) {
        char op = pop();
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = op;
        newNode->next = NULL;
        resultTail->next = newNode;
        resultTail = newNode;
    }

    return resultHead;
}

// 리스트 출력
void printList(Node* head) {
    while (head != NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

// 노드 생성
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 테스트
int main() {
    // 예시 식: A + B * C
    Node* head = createNode('A');
    head->next = createNode('+');
    head->next->next = createNode('B');
    head->next->next->next = createNode('*');
    head->next->next->next->next = createNode('C');

    printf("중위 표기법: ");
    printList(head);

    Node* postfix = infixToPostfix(head);

    printf("후위 표기법: ");
    printList(postfix);

    return 0;
}
