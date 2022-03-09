#include<stdio.h>

int linearSearch(int arr[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == num)
            return i;
    return -1;
}

int main(void)
{
    int arr[] = { 5, 7, 1, 3, 9 }, num, i, res;
    printf("Enter number to search : ");
    scanf("%d", &num);
  
    res = linearSearch(arr, 5, num);
    
    if(res==-1){
    	printf("Element is not present");
	}
	else{
		printf("Element is present in array at index %d", res);
	}
    return 0;
}

