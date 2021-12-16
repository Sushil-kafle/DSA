#include <stdio.h>
#include <stdlib.h>

int i;
void initialize(int *arr, int size)
{
    printf("Enter %d items: \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void insert(int *arr, int size, int element, int index, int *len)
{

    if (index > *len)
    {
        index = *len;
    }
    for (i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    printf("%d is inserted at %d \n", element, index);
    *len = *len + 1;
}

void deletion(int *arr, int *size, int index)
{
    if (index > *size)
    {
        printf("index exceeds the element\n");
    }
    else
    {

        printf("%d is deleted from %d \n", arr[index], index);
        for (i = index; i < *size; i++)
        {
            arr[i] = arr[i + 1];
        }
        *size = *size - 1;
    }
}

void traverse(int *arr, int size)
{
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void merge(int *arr1, int len1, int *arr2, int len2, int *arr3, int *len3)
{
    int j;
    for (i = 0; i < len1; i++)
    {
        arr3[i] = arr1[i];
        *len3 = *len3 + 1;
    }
    for (i = 0; i < len2; i++)
    {
        arr3[*len3] = arr2[i];
        *len3 = *len3 + 1;
    }
}
void update(int *arr, int element, int index)
{
    arr[index] = element;
}
int main()
{
    int arr[20];
    int arr2[20];
    int arr3[20];
    int len = 5;
    int len2 = 5;
    int len3 = 0;
    int choice, element, index, num;
    initialize(arr, 5);
    while (1)
    {
        printf("Enter a choice: 1.Insert 2.Delete 3.Traverse 4.Merge 5.Update 6.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter an element to insert: \n");
            scanf("%d", &element);
            printf("Enter a position: \n");
            scanf("%d", &index);

            insert(arr, len, element, index, &len);
            break;
        }
        case 2:
        {
            printf("Enter an index to deletion: \n");
            scanf("%d", &index);
            deletion(arr, &len, index);
            break;
        }
        case 3:
        {

            traverse(arr, len);

            break;
        }
        case 4:
        {
            initialize(arr2, 5);
            merge(arr, len, arr2, len2, arr3, &len3);
            break;
        }
        case 5:
            update(arr, index, element);
            break;
        case 6:
        {
            exit(0);
        }
        default:
        }
    }
}