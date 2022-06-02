#include<stdio.h>
#include<limits.h>
#include<math.h>

long long int min(long long int a, long long int b){
    return (a > b? b : a);
}

long long int findMinimumDays(long long int a[], int l, int r, int n){
    
    // base case
    if(l<0 || r<0 || l>=n|| r>=n || l>r) return 0;
    if(l==r) return a[l];
    
    // some trivial base cases
    if(a[l]==0 && a[r]==0) return findMinimumDays(a,l+1,r-1,n);
    if(a[l]==0) return findMinimumDays(a,l+1,r,n);
    if(a[r]==0) return findMinimumDays(a,l,r-1,n);

    // compute the answer
    long long int ans= a[l];
    
    int j=l; // index of the assignment which will get completed this time.
    for(int i=l;i<=r;i++){
        if(a[i]<ans){
            ans = a[i];
            j=i;
        }
    }

    // subtract the minimum_days of the current segment
    for(int i=l;i<=r;i++){
        a[i] -= ans;
    }
    // return the answer for current segment + left segment + right segment
    return ans + findMinimumDays(a,l,j,n)+findMinimumDays(a,j+1,r,n);
}
 
long long int solve(long long int a[], int n){
    // compute the minimum number of days required
    // to solve all assignments in the segment [1....n] initially.
    long long int minimum_days = INT_MAX;
    for(int i=0;i<n;i++){
        minimum_days = min(a[i], minimum_days);
    }

    for(int i=0;i<n;i++){
        a[i]-=minimum_days;
    }
    
    // now we have the array in the form of
    // [a1 - minimum_days, .....,  aj - minimum_days....... , an-minimum_days]
    // it must contain assignments which have been completed
    // meaning some elements in the array must have become 0's.
    
    // ask recursion to do the same process above
    // to solve small subproblems
    // i.e. finding minimum number of days to solve assignments in the smaller subsegments.
    // until all elements in the array are 0.
    
    //now keep 2 pointers to compute the starting & ending index
    // of the subsegments, until all elements are 0.
    int l=0, r=0;
    
    // enter the while loop
    while(r < n){
        
        // until we find any assignment which has been completed we
        // can choose the rth assignment also.
        if(a[r] != 0){
            r++;
        }
        else{
            
            // compute the minimum_days required to solve the assignments in
            // this subsegment
            minimum_days += findMinimumDays(a, l, r,n);
            l=r; // update the lth index
            r++; // increment r
        }
    }
    // in case the last sub-segment's answer is not computed
    // we make a recursion call for the same
    if(l<r){
        minimum_days += findMinimumDays(a,l,r-1,n);
    }
    return minimum_days;
}
 
int main() {
    // take input
    int n;
    scanf("%d", &n);
    // create an array
    long long int a[n];
    // take the array as input
    for(int i=0;i<n;i++){
        scanf("%lld", &a[i]);
    }
    // call the function to return the output
    printf("%lld\n", solve(a,n));
    return 0;
}
