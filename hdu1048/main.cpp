#include <stdio.h>
#include <string.h>
int main()
{
    freopen("in.txt","r", stdin);
    char st[20];
    while(scanf("%s",st) && strcmp(st, "ENDOFINPUT")!=0)
    {
        char ch;
        getchar();
        while((ch = getchar())!='\n')
        {
            if(ch>='A' && ch<='Z')
                putchar((ch-'A'+26-5)%26+'A');
            else
                putchar(ch);
        }
        printf("\n");
        scanf("%s",st);
    }
    return 0;
}