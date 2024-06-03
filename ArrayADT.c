#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *array;
    int usedLength;
    int finalLength;
};
void allocateMemory(struct Array *arr, int usedLength, int finalLength)
{
    arr->array = (int *)malloc(sizeof(int) * finalLength);
    arr->usedLength = usedLength;
    arr->finalLength = finalLength;
}
void initializeArray(struct Array *arr)
{
    for (int i = 0; i < arr->usedLength; i++)
    {
        int n;
        printf("enter a number at %d position : ", i);
        scanf("%d", &n);
        arr->array[i] = n;
    }
}
void printArray(struct Array *arr)
{
    for (int i = 0; i < arr->usedLength; i++)
    {
        printf("%d -> ", arr->array[i]);
    }
    printf("end\n");
}
void insertWithoutOrder(struct Array *arr, int position, int element)
{
    if (arr->usedLength < position)
    {
        printf("insertion is not possible at that place\n");
    }
    if (arr->finalLength <= arr->usedLength)
    {
        allocateMemory(arr, arr->finalLength, arr->finalLength + 1);
    }
    arr->array[arr->usedLength] = arr->array[position - 1];
    arr->array[position - 1] = element;
    arr->usedLength++;
}
int binarySearch(struct Array *arr, int element)
{
    int first = 0, last = arr->usedLength - 1, mid = (first + last) / 2;

    while (first <= last)
    {
        if (arr->array[mid] < element)
        {
            first = mid + 1;
        }
        else if (element == arr->array[mid])
        {
            return mid;
        }
        else
        {
            last = mid - 1;
        }
        mid = (first + last) / 2;
    }
    return -1;
}
int main()
{
    struct Array *arr;
    allocateMemory(arr, 5, 10);
    initializeArray(arr);
    printArray(arr);
    insertWithoutOrder(arr, 2, 88);
    printArray(arr);
    printf("88 is present in %d position", binarySearch(arr, 88));
    return 0;
}