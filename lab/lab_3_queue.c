#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue
{
    int *data;
    int max_size;
    int front;
    int rear;
};
typedef struct queue qt;

void initialize(qt *q, int size)

{
    q->data = (int *)malloc(size * sizeof(int));
    q->max_size = size;
    q->front = 0;
    q->rear = -1;
}
bool isEmpty(qt *q)
{
    return (q->front > q->rear);
}
bool isFull(qt *q)
{
    return (q->rear == (q->max_size - 1));
}

void enqueue(qt *q, int new_item)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
        exit(0);
    }

    q->data[++q->rear] = new_item;
    printf("%d is added \n", new_item);
}
int dequeue(qt *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        exit(1);
    }

    return q->data[q->front++];
}

void traverse(qt *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d\n", q->data[i]);
    }
}

int main()
{

    qt q1;
    qt *q = &q1;

    int choice, element, size;

    printf("Enter the size of queue: \n");
    scanf("%d", &size);

    initialize(q, size);

    while (1)
    {
        printf("Enter the choice\n1.Enqueue\n 2.Dequeue \n3.Traverse \n4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
        {
            printf("Enter the element to insert\n");
            scanf("%d", &element);
            enqueue(q, element);
            break;
        }
        case 2:

        {

            printf("%d is popped \n", dequeue(q));
            break;
        }
        case 3:
            traverse(q);
            break;

        case 4:
            exit(0);
        default:
            printf("Enter the valid choice");
        }
    }
}