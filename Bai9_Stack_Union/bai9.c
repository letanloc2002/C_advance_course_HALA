#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// size
// top
// mảng
typedef struct
{
    /* data */
    int *item; // mảng lưu trữ giá trị các phần tử
    int size;  // số lượng phần tử tối đa của stack
    int top;   // chỉ số lấy giá trị ở đỉnh
} Stack;
void init(Stack *stack, int newSize)
{
    stack->size = newSize;
    stack->item = (int *)malloc(newSize);
    stack->top = -1;
}

bool isEmpty(Stack stack)
{
    return (stack.top == -1 ? true : false);
}
bool isFull(Stack stack)
{
    return (stack.top == (stack.size - 1) ? true : false);
}
void push(Stack *stack, int data)
{
    if (isFull(*stack))
    {
        printf("Stack is full!! Can not add more item\n");
    }
    else
    {
        // stack->top++;
        // stack->item[stack->top] = data;
        stack->item[++stack->top] = data;
    }
}
int pop(Stack *stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack is empty!!!\n");
        return -1;
    }
    else
    {
        int val = stack->item[stack->top];
        stack->item[stack->top--] = 0;
        return val;
    }
}
void top(Stack stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!!!\n");
        return -1;
    }
    else
    {
        return stack.item[stack.top];
    }
}
int main()
{
    Stack stack1;
    init(&stack1, 5);
    printf("Push process\n");
    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);
    push(&stack1, 60);
}