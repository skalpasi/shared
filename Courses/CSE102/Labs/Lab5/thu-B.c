#include <stdio.h>
#include <stdlib.h>

struct node {
    long long int val;
    struct node *next;
};

struct node *allocate(long long int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void printk(struct node* head, int k) {
    if (!k) return;
    printf("%lld ", head->val);
    printk(head->next, k - 1);
}

struct node* deletek(struct node* head, int k) {
    struct node* temp = head;
    for (int i = 0; i < k - 1; i++) temp = temp->next;
    temp->next = temp->next->next;
    return temp->next;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d %d", &n, &k);
    struct node *head = NULL;
    struct node *temp = NULL;
    for (int i = 0; i < n; i++) {
        long long int x; scanf("%lld", &x);
        if (!head) {
            head = allocate(x);
            temp = head;
        }
        else {
            temp->next = allocate(x);
            temp = temp->next;
        }
    }
    temp->next = head;

    for (int i = 0; i < n; i++) {
        printk(head, k);
        head = deletek(head, k);
        printf("\n");
    }
}