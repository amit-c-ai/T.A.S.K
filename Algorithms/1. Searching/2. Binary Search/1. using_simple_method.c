#include<stdio.h>
int main()
{
    int a[] = { 1, 3, 5, 7, 9 }, num, flag=0, low=0, high=4, mid;
    printf("Enter number to search : ");
    scanf("%d", &num);

  	while(low<=high){
    	mid=(low+high)/2;
    	if(num==a[mid]){
      		flag=1;
     		break;
    	}
    	else if(num<a[mid])
      		high=mid-1;

    	else
    	  low=mid+1;
    
  	}	
  	if(flag==1){
    	printf("Element is found at index %d.\n", mid);
  	}
  	else{
    	printf("Element is not found.\n");
  	}
  	
  	return 0;
}

