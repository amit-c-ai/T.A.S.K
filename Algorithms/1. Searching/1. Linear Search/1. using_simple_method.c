#include<stdio.h>
int main(void)
{
    int arr[] = { 5, 7, 1, 3, 9 }, num, i;
    printf("Enter number to search : ");
    scanf("%d", &num);
  
    for (i = 0; i < 5; i++)
        if (arr[i] == num){
        	printf("Element is present in array at index %d", i);
        	return 0;
		}
    printf("Element is not present");
    
    return 0;
}

