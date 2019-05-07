#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char ch = getchar(), last_ch = ch;
        int cnt = 1;
        while((ch=getchar())!='\n')
        {
            if(ch == last_ch)
                cnt ++;
            else{
                if(cnt == 1)
                    printf("%c", last_ch);
                else
                    printf("%d%c", cnt, last_ch);
                cnt = 1;
                last_ch = ch;
            }
        }
        if(cnt == 1)
            printf("%c", last_ch);
        else
            printf("%d%c", cnt, last_ch);
        putchar('\n');
    }
    return 0;
}
