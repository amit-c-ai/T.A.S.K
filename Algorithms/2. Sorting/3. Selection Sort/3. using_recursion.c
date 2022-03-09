#include <stdio.h>

int minIndex(int a[], int i, int j)
{
	if (i == j)
		return i;
	int k = minIndex(a, i + 1, j);
	return (a[i] < a[k])? i : k;
}

void SelectionSort(int a[], int n, int index = 0)
{
	if (index == n)
	return;
	int k = minIndex(a, index, n-1);
	if (k != index)
	swap(a[k], a[index]);
	SelectionSort(a, n, index + 1);
}

int main(){
	int *arr=NULL, n, i;
	printf("Enter size of array : ");
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	
	printf("Enter array elements : ");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Array before sorting\n");
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}

	insertionSort(arr, n);

	printf("\nArray after sorting\n");
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}  
	return 0;
}

