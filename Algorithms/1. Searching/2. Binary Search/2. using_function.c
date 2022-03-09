#include<stdio.h>

int binarySearch(int a[], int num)
{
	int flag=0, low=0, high=4, mid;
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
    	return mid;
  	}
  	else{
    	return -1;
  	}
}

int main()
{
    int a[] = { 1, 3, 5, 7, 9 }, num, res;
    printf("Enter number to search : ");
    scanf("%d", &num);

	res = binarySearch(a, num);

    if(res==-1){
    	printf("Element is not present");
	}
	else{
		printf("Element is present in array at index %d", res);
	}
    return 0;
}

