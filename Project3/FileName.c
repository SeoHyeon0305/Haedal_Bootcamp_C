#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct {
    Person* data;
    int top;
    int capacity;
} Stack;

void init_stack(Stack* stack, int capacity) {
    if (capacity <= 0) capacity = 1;
    stack->data = (Person*)malloc((size_t)capacity * sizeof(Person));
    if (!stack->data) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = capacity;
}

void resize_stack(Stack* stack) {
    // 용량 2배 (오버플로 약간의 방어)
    size_t newcap = (size_t)stack->capacity * 2u;
    if (newcap < (size_t)stack->capacity) {
        fprintf(stderr, "capacity overflow\n");
        free(stack->data);
        exit(1);
    }
    Person* tmp = (Person*)realloc(stack->data, newcap * sizeof(Person));
    if (!tmp) {
        fprintf(stderr, "realloc failed\n");
        free(stack->data);
        exit(1);
    }
    stack->data = tmp;
    stack->capacity = (int)newcap;
}

int is_empty(Stack* stack) {
    return stack->top == -1;
}

int is_full(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, const char* name, int age) {
    if (is_full(stack)) {
        resize_stack(stack);
    }
    stack->top++;

    // 안전한 문자열 복사 (이식성 좋음)
    // MSVC에서도 동작하고 C4996 경고 없음
    snprintf(stack->data[stack->top].name,
        sizeof(stack->data[stack->top].name),
        "%s", name);

    stack->data[stack->top].age = age;
}

Person pop(Stack* stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack is empty!\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

Person peek(Stack* stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack is empty!\n");
        exit(1);
    }
    return stack->data[stack->top];
}

int main(void) {
    Stack stack;
    init_stack(&stack, 2);

    push(&stack, "Alice", 25);
    push(&stack, "Bob", 30);
    printf("current stack capacity: %d\n", stack.capacity);

    push(&stack, "Charlie", 35); // 자동 확장
    printf("current stack capacity: %d\n\n", stack.capacity);

    while (!is_empty(&stack)) {
        Person p = pop(&stack);
        printf("Popped: %s, %d\n", p.name, p.age);
    }

    free(stack.data);
    return 0;
}
int peek()
{
    if (is_empty()) // 스택이 비어있다면
    {
        printf("stack is empty!\n");
        return -1;
    }
    return stack[top];
}

int main()
{
    push(1);
    push(2);
    push(3);

    printf("Amount of data: %d\n", top + 1);

    printf("pop: %d\n", pop());
    printf("peek: %d\n", peek());
    printf("pop: %d\n", pop());
    printf("pop: %d\n", pop());
    return 0;
}