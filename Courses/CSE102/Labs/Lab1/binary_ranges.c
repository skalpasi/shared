#include <stdio.h>
int main()
{
    int n,length = 0;
    scanf("%d", &n);
    char arr[n];
    scanf("%s", arr);
    int sum1 = 0;
    for (int i = 0;arr[i]!='\0'; i++) {
        if (arr[i]=='1' && sum1>=2){
            sum1 = 3;
        }
        else if (arr[i]=='0' && sum1==1) {
            sum1 = 2;
        }
        else if (arr[i]=='1') {
            sum1 = 1;
        }
        if (arr[i]=='1') {
            length += 1;
        }
        
    }
    if (sum1 == 1 || sum1 == 2) {
        printf("YES %d", length);
    }
    else {
        printf("NO");
    }
    return 0;
}
