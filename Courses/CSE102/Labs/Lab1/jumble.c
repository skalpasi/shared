#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
int main()
{
    char str[1005],ttr[1005];
    scanf("%s",str);
    scanf("%s",ttr);
    int slen = strlen(str);
    int tlen = strlen(ttr);
    int flag=1;
    for(int i=0;i<tlen;i++) {
        char c=ttr[i];
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            flag=0;
            break;
        }
        int flag1 = 0;
        for(int j=0;j<slen;j++) {
            if(str[j]==ttr[i]) flag1=1;
        }
        if(flag1==1) continue;
        else 
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        printf("Yes\n");
    }
    else 
    {
        printf("No\n");
    }
    return 0;
}
