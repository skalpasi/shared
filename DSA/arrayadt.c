#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ArrayList {
  int *List;
  int size;
  int length;
};
void expand(struct ArrayList *arr) {
  arr->size += (arr->size) / 2;
  int *p = (int *)malloc(arr->size * sizeof(int));
  memcpy(p, arr->List, sizeof(int) * arr->size);
  // for (int i = 0; i < arr->length; i++) {
  //   p[i] = arr->List[i];
  // }
  free(arr->List);
  arr->List = p;
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void show(struct ArrayList arr) {
  for (int i = 0; i < arr.length; i++) {
    printf("%d ", arr.List[i]);
  }
  printf("\n");
}
void append(struct ArrayList *arr, int n) {
  if (arr->length == arr->size)
    expand(arr);
  arr->List[arr->length++] = n;
}
void insert(struct ArrayList *arr, int index, int n) {
  if (arr->length == arr->size) {
    expand(arr);
  }
  if (index >= arr->length || index < 0)
    return;
  for (int i = arr->length; i > index; i--) {
    arr->List[i] = arr->List[i - 1];
  }
  arr->List[index] = n;
  arr->length++;
}
void delete (struct ArrayList *arr, int index) {
  if (index < 0 || index >= arr->length)
    return;
  for (int i = index; i < arr->length - 1; i++) {
    arr->List[i] = arr->List[i + 1];
  }
  arr->length--;
}
int lsearch(struct ArrayList arr, int key) {
  for (int i = 0; i < arr.length; i++) {
    if (arr.List[i] == key) {
      return i;
    }
  }
  return -1;
}
int binsearch(struct ArrayList arr, int key) {
  int low, high, mid;
  low = 0;
  high = arr.length - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr.List[mid] > key) {
      high = mid - 1;
    } else if (arr.List[mid] < key) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}
int get(struct ArrayList arr, int index) {
  if (index >= arr.length || index < 0)
    return -1;
  return arr.List[index];
}
void set(struct ArrayList arr, int index, int key) {
  if (index >= arr.length || index < 0)
    return;
  arr.List[index] = key;
}
int max(struct ArrayList arr) {
  int max = INT_MIN;
  for (int i = 0; i < arr.length; i++) {
    if (arr.List[i] > max)
      max = arr.List[i];
  }
  return max;
}
int sum(struct ArrayList arr) {
  int total = 0;
  for (int i = 0; i < arr.length; i++)
    total += arr.List[i];
  return total;
}
void reverse(struct ArrayList *arr) {
  int mid = arr->length / 2;
  for (int i = 0; i < mid; i++)
    swap(&(arr->List[i]), &(arr->List[arr->length - i - 1]));
}
int main() {
  struct ArrayList arr;
  // initializing the ArrayList
  arr.size = 10;
  arr.List = (int *)malloc(arr.size * sizeof(int));
  arr.length = 0;
  // filling array with elements
  append(&arr, 29);
  append(&arr, 42);
  append(&arr, 71);
  append(&arr, 31);
  append(&arr, 91);
  append(&arr, 21);
  delete (&arr, 4);
  append(&arr, 81);
  insert(&arr, 1, 100);
  insert(&arr, 5, 52);
  insert(&arr, 7, 92);
  append(&arr, 231);
  append(&arr, 792);
  append(&arr, 1);
  append(&arr, 2);
  insert(&arr, 6, 67);
  delete (&arr, 3);
  reverse(&arr);
  append(&arr, 48);
  append(&arr, 84);
  append(&arr, 78);
  show(arr);
  return 0;
}
