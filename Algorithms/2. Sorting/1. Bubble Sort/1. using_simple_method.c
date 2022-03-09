#include<stdio.h>
#include<stdlib.h>
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
	
	
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
            	temp = arr[j];                                                //sorting
            	arr[j] = arr[j+1];
            	arr[j+1] = temp;
			}
	    }  	
    }      
              
	printf("\nArray after sorting\n");
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}            
	return 0;
}

