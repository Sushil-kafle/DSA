#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int max_size;
    int *data;
    int top;
};
typedef struct stack st;
void createStack(st *s)
{
    s->top = -1;
    s->max_size = 5;
    s->data = (int *)calloc(s->max_size, sizeof(int));
}

int isEmpty(st *s)
{
    if (s->top < 0)
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

    if (s->max_size - 1 <= s->top)
    {

        return 1;
    }

    else
    {

        return 0;
    }
}

void push(st *s, int newdata)
{
    int i;
    if (isFull(s))
    {
        int *temp;
        temp = (int *)calloc(s->max_size * 2, sizeof(int));
        for (i = 0; i < s->max_size; i++)
        {
            temp[i] = s->data[i];
        }

        free(s->data);
        s->data = temp;
        s->max_size *= 2;
    }
    s->top = s->top + 1;

    s->data[s->top] = newdata;
}

void pop(st *s)
{
    if (isFull(s))
    {
        printf("Stack Underflow\n");
        return;
    }
    s->top = s->top - 1;
}
void traverse(st *s)
{
    int i;
    for (i = 0; i < s->max_size; i++)
    {
        printf("%d\n", s->data[i]);
    }
}
int main()
{
    st stk;
    st *s = &stk;

    createStack(s);

    int choice;
    int num;

    while (1)
    {
        printf("Enter a choice : \n 1.Push 2.Pop 3.Traverse 4.Exit \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a number to insert\n");
            scanf("%d", &num);
            push(s, num);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            traverse(s);
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice\n");
        }
    }
}