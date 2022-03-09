#include<bits/stdc++.h>

class sorting
{
    int arr[20];
    int id;
public:
    void linearSearch(int arr[], int n, int num){
    	int i;
    	for (i = 0; i < n; i++)
        	if (arr[i] == num){
        		printf("Element is present in array at index %d", i);
				return;	
			}
    	printf("Element is not present");
	}
};
  
int main()
{
    sorting s;
    int arr[] = { 5, 7, 1, 3, 9 }, num, i, res;
    printf("Enter number to search : ");
    scanf("%d", &num);
  
    s.linearSearch(arr, 5, num);

    return 0;
}

