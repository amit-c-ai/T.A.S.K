#include<stdio.h>
#include<stdlib.h>
#define allot(n) (int *)malloc(n*sizeof(int));

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int start, int end){
	int i, pivot = arr[end], pIndex = start;
	for(i=start; i<end; i++){
		if(arr[i] <= pivot){
			swap(&arr[i], &arr[pIndex]);
			pIndex++;
		}
	}
	swap(&arr[pIndex], &arr[end]);
	return pIndex;
}

void quickSortRecur(int arr[], int start, int end){
	if(start < end){
		int pIndex = partition(arr, start, end);
		quickSortRecur(arr, start, pIndex-1);
		quickSortRecur(arr, pIndex+1, end);
	}
}

int main(void)
{
	int i, n, *arr;
    printf("Enter size of array : ");
    scanf("%d", &n);
    arr = allot(n);
    
    printf("Enter elements of array : ");
    for(i=0; i<n; i++){
    	scanf("%d", &arr[i]);
	}
	
    printf("\n\nBefore sorting : \n");
    for(i=0; i<n; i++){
    	printf("%d ", arr[i]);
	}	
		
	quickSortRecur(arr, 0, n-1);
	printf("\nAfter sorting : \n");
    for(i=0; i<n; i++){
    	printf("%d ", arr[i]);
	}	
    
    return 0;
}

