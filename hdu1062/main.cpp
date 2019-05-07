#include <stdio.h>
#include <string.h>

char* revstr(char* st)
{
    int len = strlen(st);
    for(int i=0;i<(len+1)/2;i++)
    {
        char ch = st[i];
        st[i] = st[len-1-i];
        st[len-1-i] = ch;
    }
    return st;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    char st[1001];
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char ch;
        int j = 0;
        while((ch = getchar())!='\n')
        {
            if(ch == ' ')
            {
                st[j] = '\0';
                j = 0;
                printf("%s ", revstr(st));
            }else{
                st[j++] = ch;
            }
        }
        st[j] = '\0';
        printf("%s\n", revstr(st));
    }
    return 0;
}