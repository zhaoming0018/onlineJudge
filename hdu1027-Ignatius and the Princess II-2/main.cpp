#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int fac[]= {1,1,2,6,24,120,720,5040,40320};
vector<int> v, a;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        v.clear();
        a.clear();
        int i;
        for(i=0;i<n;i++)
            v.push_back(i+1);
        m = m-1;
        for(i=1;i<8;i++)
            if(m < fac[i])  break;
        int pos = i-1;
        for(i=0;i<n-(pos+1);i++)
            a.push_back(v[i]);
        for(i=0;i<n-(pos+1);i++)
            v.erase(v.begin());
        for(int i=pos;i>=0;i--)
        {
            int r = m % fac[i];
            int t = m / fac[i];
            m = r;
            a.push_back(v[t]);
            v.erase(v.begin()+t);
        }
        printf("%d", a[0]);
        int size_a = a.size();
        for(int i=1;i<size_a;i++)
            printf(" %d", a[i]);
        printf("\n");

    }
    return 0;
}
