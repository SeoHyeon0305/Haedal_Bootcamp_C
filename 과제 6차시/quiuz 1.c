#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int capacity;
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (int*)malloc(s->capacity * sizeof(int));
}

int is_empty(StackType* s) {
    return s->top == -1;
}

int is_full(StackType* s) {
    return s->top == (s->capacity - 1);
}

void push(StackType* s, int item) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (int*)realloc(s->data, s->capacity * sizeof(int));
    }
    s->data[++(s->top)] = item;
}

int pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack is Empty\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

int main() {
    StackType s;
    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("%d\n", pop(&s)); // 30
    printf("%d\n", pop(&s)); // 20
    printf("%d\n", pop(&s)); // 10

    free(s.data); 
    return 0;
}