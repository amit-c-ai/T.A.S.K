#include <stdio.h>

void selectionSort(int arr[], int n){
	int i, min_idx, j;
	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;
		swap(&arr[min_idx], &arr[i]);
	}
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

	selectionSort(arr, n);

	printf("\nArray after sorting\n");
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}  
	return 0;
}

