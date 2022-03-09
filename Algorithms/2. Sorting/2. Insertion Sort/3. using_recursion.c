#include <stdio.h>

void insertionSort(int arr[], int n)
{
	if (n <= 1)
		return;
	insertionSort( arr, n-1 );
	int last = arr[n-1];
	int j = n-2;

	while (j >= 0 && arr[j] > last)
	{
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = last;
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

