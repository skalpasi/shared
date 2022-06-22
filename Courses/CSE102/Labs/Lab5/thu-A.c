#include <stdio.h>
#include <stdlib.h>

struct node {
    long long val;
    struct node *next;
};

struct node *allocate(long long val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

struct node* push(struct node* head, long long val) {
    struct node* temp = allocate(val);
    temp->next = head;
    return temp;
}

struct node* krev(struct node* head, int k) {
    struct node* st = NULL;
    for (int i = 0; i < k; i++) {
        st = push(st, head->val);
        head = head->next;
    }
    struct node* st2 = NULL;
    while(head) {
        st2 = push(st2, head->val);
        head = head->next;
    }
    while(st) {
        st2 = push(st2, st->val);
        st = st->next;
    }
    return st2;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d", &n);
    struct node *head = NULL;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int q; scanf("%d", &q);
        if (q == 1) {
            long long x; scanf("%lld", &x);
            head = push(head, x);
            s++;
        }
        else if (q == 2) {
            head = head->next;
            s--;
        }
        else {
            int k; scanf("%d", &k);
            head = krev(head, s - k);
        }
        if (head == NULL) printf("EMPTY\n");
        else printf("%lld\n", head->val);
    }
}