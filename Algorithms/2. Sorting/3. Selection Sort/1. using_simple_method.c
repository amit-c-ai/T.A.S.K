#include <stdio.h>

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int main(){
	int *arr=NULL, n, i, k, j, min_index;
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

	for (i = 0; i < n-1; i++)
	{
		min_index = i;
		for (j = i+1; j < n; j++){
		    if (arr[j] < arr[min_index]){
			min_index = j;
		    }
		}
		swap(&arr[min_index], &arr[i]);
	}

	printf("\nArray after sorting\n");
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}  
	return 0;
}

