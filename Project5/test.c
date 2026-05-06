#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// 큐 초기화
void init_queue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// 큐가 비었는지 확인
int is_empty(Queue* q) {
    if (q->front == q->rear)
        return 1;
    return 0;
}

// 큐가 가득 찼는지 확인
int is_full(Queue* q) {
    if (q->rear == MAX_SIZE - 1)
        return 1;
    return 0;
}

// 데이터 추가
void enqueue(Queue* q, int value) {
    if (is_full(q)) {
        printf("Queue is full!\n");
        return;
    }

    q->rear++;
    q->data[q->rear] = value;
}

// 데이터 삭제
int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    q->front++;
    int value = q->data[q->front];

    return value;
}

// 맨 앞의 데이터 확인
int peek(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = q->data[q->front];

    return value;
}

void queue_print(Queue* q) {
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (i <= q->front || i > q->rear)
            printf("  | ");
        else
            printf("%2d| ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    init_queue(&q);

    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);

    dequeue(&q); queue_print(&q);
    dequeue(&q); queue_print(&q);
    dequeue(&q); queue_print(&q);

    return 0;
}