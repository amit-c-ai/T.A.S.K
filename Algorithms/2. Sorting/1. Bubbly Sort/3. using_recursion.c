#include<stdio.h>
#include<stdlib.h>

void swap(int *left, int *right){
	int temp = *left;
	*left = *right;
	*right = temp;
}

void bubbleSort(int arr[], int n){
    if (n == 1)
        return;
 
	int i;
    for (i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap(&arr[i], &arr[i+1]);

    bubbleSort(arr, n-1);
}

int main(void){
	int *arr=NULL, n, i, j, left, right, temp;
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
	
	bubbleSort(arr, n);
      
              
	printf("\nArray after sorting\n");
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}            
	return 0;
}

