#include <stdio.h>

struct stack
{
    int top;
    int *items;
    int size;
};
typedef struct stack st;

void makeStack(st *s, int size)
{
    s->top = -1;
    s->size = size;
    s->items = (int *)calloc(size, sizeof(int));
}

int isEmpty(st *s)
{
    if (s->top < 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(st *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(st *s, int newItem)
{
    if (isFull(s))
    {
        printf("Stack is Full");
    }
    else
    {
        s->top = s->top + 1;
        s->items[s->top] = newItem;
        printf("%d is added in the stack", newItem);
    }
}

void pop(st *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty");
    }

    else
    {
        printf("%d is removed", s->items[s->top]);
        s->top = s->top - 1;
    }
}

int main()
{

    st s1;
    st *s = &s1;
    // pop(s);
}