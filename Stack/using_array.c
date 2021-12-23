#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isEmpty(st *s)
{
    return s->top < 0;
}

bool isFull(st *s)
{

    return s->top == s->size - 1;
}

void push(st *s, int newItem)
{
    if (isFull(s))
    {
        printf("Stack is Full\n");
        exit(0);
    }
    else
    {
        s->items[++s->top] = newItem;
        printf("%d is added in the stack\n", newItem);
    }
}

void pop(st *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        exit(0);
    }

    else
    {
        printf("%d is removed.\n", s->items[s->top--]);
    }
}

int main()
{

    st s1;
    st *s = &s1;

    makeStack(s, 10);
    int choice, element, index, num;
    while (1)
    {
        printf("Enter a choice: \n1.Push 2.Pop 3.Top 4.Size 5.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter an element to push: \n");
            scanf("%d", &element);
            push(s, element);
            break;
        }
        case 2:
        {
            pop(s);
            break;
        }
        case 3:
        {
            if (isEmpty(s))
            {
                printf("Stack is empty\n");
                exit(0);
            }
            else
            {
                printf("The top of the stack is %d\n", s->items[s->top]);
            }
            break;
        }
        case 4:
        {
            printf("The size of the stack is %d\n", s->top + 1);
            break;
        }
        case 5:
            exit(0);

        default:
            printf("Enter the valid choice\n");
        }
    }
}