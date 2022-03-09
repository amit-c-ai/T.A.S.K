#include<stdio.h>
#include<stdlib.h>
#define allot(n) (int *)malloc(n*sizeof(int));

void merge(int left[], int l, int right[], int r, int A[]){
	int i=0, j=0, k=0;
	while(i<l && j<r){
		if(left[i] <= right[j]){
			A[k] = left[i];
			i++;
		}
		else{
			A[k] = right[j];
			j++;
		}
		k++;
	}
	while(i<l){
		A[k] = left[i];
		i++; k++;
	}
	while(j<r){
		A[k] = right[j];
		j++; k++;
	}
}

void mergeSortRecur(int arr[], int n){
	if(n<2){
		return;
	}
	int i, mid = n/2, midr = n - mid, *left, *right;
	left = allot(mid);
	right = allot(midr);
	
	for(i=0; i<n; i++){
		if(i<mid){
			left[i] = arr[i];
		}
		else{
			right[i-mid] = arr[i];
		}
	}
	
	mergeSortRecur(left, mid);
	mergeSortRecur(right, n-mid);
	merge(left, mid, right, n-mid, arr);
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
		
	mergeSortRecur(arr, n);
	printf("\n\nAfter sorting : \n");
    for(i=0; i<n; i++){
    	printf("%d ", arr[i]);
	}	
    
    return 0;
}

