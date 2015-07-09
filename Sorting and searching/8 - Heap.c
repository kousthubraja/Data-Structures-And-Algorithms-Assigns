#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WSIZE 20
 
struct Heap
{
    int size;
    char *array;
};

void swap(char* a, char* b) {
	char tmp[WSIZE];
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
}

void heapify(struct Heap* heap, int i)
{
    int largest = i;  
    int left = (i << 1) + 1;
    int right = (i + 1) << 1;
	 
    if (left < heap->size &&
        strcmp(heap->array+left*WSIZE, heap->array+largest*WSIZE)>0)
        largest = left;

    if (right < heap->size &&
		strcmp(heap->array+right*WSIZE, heap->array+largest*WSIZE)>0)
        largest = right;
 
    if (largest != i)
    {
        swap(heap->array+largest*WSIZE, heap->array+i*WSIZE);
        heapify(heap, largest);
    }
}
 
struct Heap* buidHeap(char *array, int size)
{
    int i;
    struct Heap* heap =
              (struct Heap*) malloc(sizeof(struct Heap));
    heap->size = size;  
    heap->array = array;

    for (i = (heap->size - 2) / 2; i >= 0; --i)
        heapify(heap, i);
    return heap;
}
 
void heapSort(char* array, int size)
{
    struct Heap* heap = buidHeap(array, size);
 
    while (heap->size > 1)
    {

        swap(heap->array, heap->array+(heap->size - 1)*WSIZE);
        --heap->size;
        heapify(heap, 0);
    }
}
 
void err(){
	printf("*** Error ***\n");
	exit(1);
}

 
int main()
{
	long int size, i;
	char *arr;
	time_t t;
		
	if(!scanf("%ld", &size) || size<=0)
		err();
		
	arr = (char*) malloc(sizeof(char) * size * WSIZE);
	
	if(!arr)
		err();
		
	for(i = 0; i<size ; i++){
		if(scanf("%s", arr+i*WSIZE)>20)
			err();
 	}
 	
 	t = time(NULL);
 	   
    heapSort(arr, size);
 
 	t = time(NULL) - t;
 	
 	printf("\nSorted list :\n");
	for(i = 0; i<size ; i++)
		printf("%s\n", arr+i*WSIZE);

	printf("\n #Running time : %f\n", (float)t/1000.0);
	
	free(arr);
	
    return 0;
}
