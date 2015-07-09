#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void err(){
	printf("*** Error ***\n");
	exit(1);
}

int lsr(int A[], int p, int r, int k){
	if(p > r)
		return -1;
	else{
		if(A[p] == k)
			return p;
		else
			lsr(A, p+1, r, k);
	}
}

int main(){
	int n, i, k, pos;
	int *a;
	time_t t;
	
	if(!scanf("%d", &n) || n<=0)
		err();
	
	a = (int*) malloc(sizeof(int)*(n+1));
	
	for(i=1;i<=n;i++){
		if(!scanf("%d", &a[i]))
			err();
	}
	
	if(!scanf("%d", &k))
		err();
	
	t = time(NULL);
	
	pos = lsr(a, 1, n, k);
	
	t = time(NULL) - t;
	
	printf("Position : %d\n", pos);
	printf("Running time : %f\n", (float)t/1000.0);
	
	return 0;
}


