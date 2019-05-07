#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
    int n;
    char train_in[10], train_out[10];
    int que[20];
    stack<char> s;
    while(scanf("%d%s%s",&n,train_in, train_out)!=EOF)
    {
        int step = 0, k = 0;
        while(!s.empty())   s.pop();
        memset(que, 0, sizeof(que));
        /*
            坑在序号可以重复上
        */
        for(int i=0;i<n;i++)
        {
            if(!s.empty() && s.top() == train_out[i])
            {
                que[step++] = 1;
                s.pop();
            }else{
                while(train_in[k]!=train_out[i] && k<n)
                {
                    s.push(train_in[k]);
                    que[step++] = 0;
                    k++;
                }
                if(k == n)  break;
                else{
                    s.push(train_in[k]);
                    que[step++] = 0;
                    k++;
                    s.pop();
                    que[step++] = 1;
                }
            }
        }
        if(step == 2*n)
        {
            printf("Yes.\n");
            for(int i=0;i<step;i++)
                printf("%s\n", que[i]==0?"in":"out");
            printf("FINISH\n");
        }else{
            printf("No.\nFINISH\n");
        }
    }
    return 0;
}
