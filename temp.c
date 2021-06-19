#include<stdio.h>
int main(){
	int a, *ptr, **ktr;
	a=12;
	ptr = &a;
	ktr = &ptr;
	printf("%u %u %u", &a, &ptr, ktr);
	return 0;
}
