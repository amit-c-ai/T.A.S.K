#include<stdio.h>

int binarySearch(int arr[], int p, int r, int num) {
   if (p <= r) {
      int mid = (p + r)/2;
      if (arr[mid] == num)
         return mid ;
      if (arr[mid] > num)
         return binarySearch(arr, p, mid-1, num);
      if (arr[mid] < num)
         return binarySearch(arr, mid+1, r, num);
   }
   return -1;
}


int main()
{
    int a[] = { 1, 3, 5, 7, 9 }, num, res;
    printf("Enter number to search : ");
    scanf("%d", &num);

	res = binarySearch(a, 0, 4, num);

    if(res==-1){
    	printf("Element is not present");
	}
	else{
		printf("Element is present in array at index %d", res);
	}
    return 0;
}

