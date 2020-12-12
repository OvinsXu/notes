#include<stdio.h>

int main(void){
	int n,i;
	A:
	printf("Input a number n£º£¨n<100£©\t") ;
	scanf("%d",&n);
	if(n>=100)goto A;
	long long a[n];

	a[0] = 0;
	a[1] = 1;
	printf("%d\n%d\n",a[0],a[1]);
	for(i = 2;i < n;i++){
		a[i] = a[i-1] + a[i-2];
		printf("%lld\n",a[i]);
	}
	return 0;
}
