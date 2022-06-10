#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
long long int a[200005];
bool good(int n, long long int k,long long int mid) 
{
    long long int sum=0;
    for(int i=0;i<n;++i){
        sum+=mid/a[i];
        if(sum >= k) { 
            break;
        }
    }
    return sum>=k;
}
 
long long int bin(int n, long long int k) {
    long long int ans=0,maxi=0;
    for(int i=0;i<n;++i) maxi=max(maxi,a[i]);
    long long int l=0,r=k*maxi+1;
    while(l<=r) {
        long long int mid=l+(r-l)/2;
        if(l==r){
            if(good(n,k,mid)){
                ans=mid;
                r=mid-1;
            }
            break;
        }
        if(good(n,k,mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
 
int main()
{
    int n;
    scanf("%d",&n);
    long long int k;
    scanf("%lld",&k);
    for(int i=0;i<n;++i) cin>>a[i]; scanf("%lld",&a[i]);
    printf("%lld",bin(n,k));
    return 0;
}
