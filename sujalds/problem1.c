#include <stdio.h>
#include <stdlib.h>
struct Array
{
	int *arr;
	int totalLength;
	int usedLength;
};

void allcateMemory(struct Array *array, int usedLength, int totalLength)
{
	array->totalLength = totalLength;
	array->usedLength = usedLength;
	array->arr = (int *)malloc(sizeof(int) * totalLength);
}
void initializeArray(struct Array *array)
{
	int n;
	for (int i = 0; i < array->usedLength; i++)
	{
		printf("enter the element on position %d : ", i);
		scanf("%d", &n);
		array->arr[i] = n;
	}
}
void traverse(struct Array *array)
{
	for (int i = 0; i < array->usedLength; i++)
	{
		printf("%d ", array->arr[i]);
	}
	printf("\n");
}

void insert(struct Array *array, int position, int element)
{
	if (position > (array->usedLength))
	{
		printf("\ninsertion is not possible\n");
		return;
	}
	for (int i = array->usedLength; i >= position; i--)
	{
		array->arr[i + 1] = array->arr[i];
	}
	array->arr[position] = element;
	array->usedLength++;
}

void delete(struct Array *array, int position)
{
	if (position > array->usedLength - 1)
	{
		printf("\ndeletion is not possible\n");
	}
	for (int i = position; i < array->usedLength; i++)
	{
		array->arr[i] = array->arr[i + 1];
	}
	array->usedLength--;
}

void sort(struct Array *array)
{
	for (int i = 0; i < array->usedLength; i++)
	{
		int position = i;
		for (int j = i + 1; j < array->usedLength; j++)
		{
			if (array->arr[j] < array->arr[position])
			{
				position = j;
			}
		}
		if (position != i)
		{
			int temp = array->arr[position];
			array->arr[position] = array->arr[i];
			array->arr[i] = temp;
		}
	}
}

int search(struct Array *array, int element)
{
	for (int i = 0; i < array->usedLength; i++)
	{
		if (element == array->arr[i])
		{
			return i;
		}
	}
}

void modify(struct Array *array, int element, int replace)
{
	int temp = search(array, element);
	if (temp == -1)
	{
		printf("\nthe number is not present in the array\n");
		return;
	}
	array->arr[temp] = replace;
}
void display(struct Array *array)
{
	traverse(array);
}

int main()
{
	struct Array array;
	allcateMemory(&array, 4, 10);
	initializeArray(&array);

	int number = 1;
	while (number != 0)
	{
		printf("enter \n 1 for traverse || 2 for insert|| 3 for delete || 4 for sort || 5 for modify || 6 for search || 7 for display\n enter 0 to exit from the loop\n");

		printf("enter a number from 1 to 7 : ");
		scanf("%d", &number);
		switch (number)
		{
		case 1:
		{
			traverse(&array);
			break;
		}
		case 2:
		{
			printf("enter the position and number to insert : ");
			int a, b;
			scanf("%d %d", &a, &b);
			insert(&array, a - 1, b);
			traverse(&array);
			break;
		}
		case 3:
		{
			printf("enter the position to delete : ");
			int a;
			scanf("%d", &a);
			delete (&array, a - 1);
			traverse(&array);
			break;
		}
		case 4:
		{
			sort(&array);
			traverse(&array);
			break;
		}
		case 5:
		{
			printf("enter the number which is going to replace also enter the number from which you liked to replace the existing number : ");
			int a, b;
			scanf("%d %d", &a, &b);
			modify(&array, a, b);
			traverse(&array);
			break;
		}
		case 6:
		{
			printf("enter the number to search : ");
			int a;
			scanf("%d", &a);
			int num1 = search(&array, a);
			if (num1 == -1)
			{
				printf("\nthe number is not present in the array\n");
				break;
			}
			printf("the position at which %d is present is : %d\n", a, num1 + 1);
			break;
		}
		case 7:
		{
			display(&array);
			break;
		}
		default:
		{
			printf("an invalid input\n");
			break;
		}
		}
	}
	printf("Thank you for using our programm!");
	return 0;
}
