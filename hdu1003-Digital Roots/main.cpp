#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    int sum;
    char st[1010];
    while(scanf("%s",st) && st[0]!='0')
    {
        while(true)
        {
            int len = strlen(st);
            if(len == 1)
            {
                printf("%s\n",st);
                break;
            }
            sum = 0;
            for(int i=0;i<len;i++)
                sum += st[i]-'0';
            int t = 0;
            while(sum!=0)
            {
                st[t] = sum % 10 + '0';
                sum = sum / 10;
                t++;
            }
            st[t] = '\0';
        }
    }
    return 0;
}
