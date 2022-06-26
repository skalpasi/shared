#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/* binary heaps are implemented usig commplete binary trees
 each parent node should be equal to or greater tha its descadant
 height of heap is always log(n) -- n is number of nodes */

void swap(int*a,int*b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
/* you can only delete the highest priority element */
void delete(int**a,int*n){
    int*b=(int*)malloc((*n-1)*sizeof(int));
    (*a)[0]=(*a)[(*n)-1];
    for(int i=0;i<(*n)-1;i++)b[i]=(*a)[i];
    int i=0;
    while(true){
        if(b[i]>=(b[2*i+1]&&b[i]>=b[2*i+2]))break;
        else if(b[2*i+1]>b[2*i+2])swap(&b[i],&b[2*i+1]);
        else swap(&b[i],&b[2*i+2]);
        i++;
    }
    *a=b;
    for (i=0; i<(*n)-1; i++) {
        printf("%d ", b[i]);
    }
    (*n)--;
}
void insert(int**a,int item,int*n) {
    int*b=(int*)malloc((*n+1)*sizeof(int));
    for(int i=0;i<*n;i++)b[i]=(*a)[i];
    b[*n]=item;
    int i=(*n);
    while(i>=0){
        if(b[i]>b[(i-1)/2])swap(&b[i],&b[(i-1)/2]);
        else break;
        i=(i-1)/2;
    }
    *a=b;
    (*n)++;
}

int main() {
    int n = 7;
    int *heap = (int *)malloc(n*sizeof(int));
    heap[0]=30, heap[1]=20, heap[2]=15, heap[3]=5;
    heap[4]=10, heap[5]=12, heap[6]=6;
    insert(&heap, 40, &n);
    insert(&heap, 35, &n);
    insert(&heap, 2, &n);
    insert(&heap, 25, &n);
    insert(&heap, 65, &n);
    delete(&heap, &n);
    printf("Heap array: \n");
    for (int i=0; i<n; i++) {
        printf("%d ", heap[i]);
    }
    return 0; 
}
