#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef long long ll;
const ll inf = 1e9;

struct E {
    ll val;
    int idx;
};

int cmpfunc (const void * a, const void * b) {
    struct E* e1 = (struct E*) a;
    struct E* e2 = (struct E*) b;
    if(e1->val - e2->val != 0) {
        return e1->val - e2->val;
    }
    else {
        return e1->idx - e2->idx;
    }
}


void solve() {
    int n;
    scanf("%d", &n);
    
    struct E a[n];
    for(int i = 0; i < n; i++) {
        scanf("%lld", &(a[i].val));
        a[i].idx = i + 1;
    }
    
    qsort(a, n, sizeof(struct E), cmpfunc);

    ll ans = 0;
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].val - tot < 0) continue;
        ll moves = (a[i].val - tot + a[i].idx) / a[i].idx;
        ans += moves;
        tot += moves * a[i].idx;
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        solve();
    }
    return 0;
}