#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int target;
char st[13];
int a[12], ha[12];

int test(int v,int w,int x,int y,int z)
{
    v = a[v];
    w = a[w];
    x = a[x];
    y = a[y];
    z = a[z];
    return v-w*w+x*x*x-y*y*y*y+z*z*z*z*z==target;
}

int main()
{
    int flag;
    while(scanf("%d%s",&target,st) && target!=0 && strcmp(st,"END")!=0)
    {
        flag = 0;
        memset(ha,0,sizeof(ha));
        int len = strlen(st);
        for(int i=0;i<len;i++)
            a[i] = st[i]-'A'+1;
        sort(a,a+len);
        for(int v=len-1;v>=0;v--)
        {
            if(flag)    break;
            ha[v] = 1;
            for(int w=len-1;w>=0;w--)
            {
                if(flag)    break;
                if(ha[w])   continue;
                ha[w] = 1;
                for(int x=len-1;x>=0;x--)
                {
                    if(flag)    break;
                    if(ha[x])   continue;
                    ha[x] = 1;
                    for(int y=len-1;y>=0;y--)
                    {
                        if(flag)    break;
                        if(ha[y])   continue;
                        ha[y] = 1;
                        for(int z=len-1;z>=0;z--)
                        {
                            if(flag)    break;
                            if(ha[z])   continue;
                            ha[z] = 1;
                            if(test(v,w,x,y,z))
                            {
                                printf("%c%c%c%c%c\n",a[v]+'A'-1,a[w]+'A'-1,a[x]+'A'-1,a[y]+'A'-1,a[z]+'A'-1);
                                flag = 1;
                            }
                            ha[z] = 0;
                        }
                        ha[y] = 0;
                    }
                    ha[x] = 0;
                }
                ha[w] = 0;
            }
            ha[v] = 0;
        }
        if(!flag)
            printf("no solution\n");
    }
    return 0;
}
