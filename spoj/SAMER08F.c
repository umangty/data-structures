#include <stdio.h>
int main(void){
	int n;
	while (1){
		scanf("%d",&n);
		if (n!=0) printf("%d\n",n*(n+1)*(2*n+1)/6);
		else break;
	}
	return 0;
}