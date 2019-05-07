#include <iostream>
#include <map>
#include <stdio.h>
#define MAXN 1000010
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        map<int,int> record;
        map<int, int>::iterator iter;
        int res;
        int flag = false;
        if(!record.empty()) record.clear();
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(flag)    continue;
            iter = record.find(x);
            if(iter == record.end())
            {
                record[x] = 1;
            }else{
                record[x] = record[x]+1;
                if(record[x]>=(n+1)/2)
                {
                    res = x;
                    flag = true;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
