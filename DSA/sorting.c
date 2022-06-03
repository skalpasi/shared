#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}
void bsort(int a[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (a[j + 1] < a[j])
        swap(a, j, j + 1);
      else
        break;
    }
  }
}
void isort(int a[], int n) {
  int i, j;
  for (i = 1; i < n; i++) {
    for (j = i; j > 0; j--) {
      if (a[j] < a[j - 1])
        swap(a, j, j - 1);
      else
        break;
    }
  }
}
void ssort(int a[], int n) {
  int i, j, min;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++)
      if (a[j] < a[min])
        min = j;
    if (min != i)
      swap(a, i, min);
  }
}
int partition(int a[], int l, int h) {
  int p = a[l];
  int i = l, j = h;
  while (true) {
    while (a[i] <= p)
      i++;
    while (a[j] > p)
      j--;
    if (i > j)
      break;
    swap(a, i, j);
  }
  swap(a, j, l);
  return j;
}
void qsort(int a[], int l, int h) {
  if (l >= h)
    return;
  int p = partition(a, l, h);
  qsort(a, l, p - 1);
  qsort(a, p + 1, h);
}
void merge(int a[], int l, int m, int h) {
  int p = m - l + 1;
  int q = h - m;
  int i = 0, j = 0, k;
  int x[p], y[q];
  for (i = 0; i < p; i++)
    x[i] = a[l + i];
  for (j = 0; j < q; j++)
    y[j] = a[m + 1 + i];
  i = 0, j = 0, k = l;
  while (i < p && j < q) {
    if (x[i] <= y[j])
      a[k++] = x[i++];
    else
      a[k++] = y[j++];
  }
  while (i < p)
    a[k++] = x[i++];
  while (j < q)
    a[k++] = y[j++];
}
void msort(int a[], int l, int h) {
  if (l < h) {
    int m = (l + h) / 2;
    msort(a, l, m);
    msort(a, m + 1, h);
    merge(a, l, m, h);
  }
}
int main() {
  int arr[10] = {1, 5, 2, 6, 7, 2, 6, 2, 9, 3};
  int len = sizeof(arr) / sizeof(arr[0]);
  // int n;
  // scanf("%d",&n);
  // int arr[n];
  // for(int j=0;j<n;j++)scanf("%d",&arr[j]);
  // bsort(arr,len);
  // isort(arr,len);
  // ssort(arr,len);
  // qsort(arr,0,len);
  msort(arr, 0, len);
  for (int k = 0; k < len; k++)
    printf("%d ", arr[k]);
  return 0;
}
