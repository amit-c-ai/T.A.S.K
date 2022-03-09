#include <stdio.h>

void insertionSort(int arr[], int n){
	int i, key, j;
	for (i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
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

	insertionSort(arr, n);

	printf("\nArray after sorting\n");
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}  
	return 0;
}

