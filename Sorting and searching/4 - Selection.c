#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WSIZE 20

void err(){
	printf("*** Error ***\n");
	exit(1);
}

int main(){
	long int n, i, j;
	char tmp[WSIZE];
	char *a;
	time_t t;
	
	if(!scanf("%ld", &n) || n<=0)
		err();
	
	a = (char*) malloc(sizeof(char)*(n+1)*WSIZE);
	
	if(!a)
		err();
	
	for(i=1;i<=n;i++){
		if(!scanf("%s", (a+i*20)))
			err();
	}
	
	t = time(NULL);
	
	for(j=1; j<=n; j++){
		for(i=j+1; i<=n; i++){
			if(strcmp((a+j*20), (a+i*20))>0){
				strcpy(tmp, a+j*20);
				strcpy(a+j*20, a+i*20);
				strcpy(a+i*20, tmp);
			}
		}
	}
	
	t = time(NULL) - t;
	
	printf("\nSorted list :\n");
	
	for(i=1; i<=n; i++)
		printf("%s\n", (a+i*20));
	
	printf("\n #Running time : %f\n", (float)t/1000.0); 
	
	free(a);
	return 0;
}


