//Selection Sort
//Complexity : O(n^2)

#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int *arr, int n)
{
	int i, j, min;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(&arr[min], &arr[i]);
	}
}

void printArray(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[5] = {64, 25, 12, 22, 11};
	int n = 5;
	selectionSort(arr, n);
	printArray(arr, n);
	return 0;
}
