#include <stdio.h>
#include <stdlib.h>
 
int n, k;
long long x;
long long arr[21];
 
int rec(int i, int length, long long sum) {
    if (length == k && sum == x) return 1;
    if (length > k || i > n - 1) return 0;
    int add = (length < k - 1) ? rec(i + 1, length + 1, sum + arr[i]) : 0;
    int mul = (length == k - 1) ? rec(i + 1, length + 1, sum * arr[i]) : 0;
    int other = rec(i + 1, length, sum);
    return add | mul | other;
}
 
int main()
{
   scanf("%d %d %lld", &n, &k, &x);
   for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
   int ans = rec(0, 0, 0);
   if (ans) printf("Yes\n");
   else printf("No\n");
   return 0;
}
