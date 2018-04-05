//Name: Grecia Gonzalez
//Summary: This program finds the largest elements of 
//file and allocates an array of size k 
//and while reading  numbers in the array  finds if modification needed


#include<stdio.h>
#include<stdlib.h>

void insertMax(int arr[], int n, int num)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (arr[i] < num)
		{
		break;
		}
	}	
	int j;

	for(j = n-1; j > i; j--)
	{
		arr[j] = arr[j-1];
	}
	arr[i] = num;
}

int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)b - *(int*)a );
}

int main(int argc, char* argv[])
{
	char *file = argv[1];
	int k = atoi(argv[2]);
	FILE *fp;
	fp = fopen(file, "r");
	int num;

	int i = 0;
	int arr[k];
	while(fscanf(fp, "%d", &num) == 1)
	{
		arr[i] = num;
		i++;

		if ( i == k) break;
	}

	qsort(arr, k, sizeof(int), cmpfunc);

	while(fscanf(fp, "%d", &num) == 1)
	{
		if (num > arr[k-1])
		{
			insertMax(arr, k, num);
		}
	}

	for(i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
		printf("\n");

		return 0;
}


