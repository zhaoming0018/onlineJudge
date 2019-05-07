#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
//#define DEBUG
#define Sloop(it, st)    for(string::iterator it=st.begin();it!=st.end();it++)
using namespace std;

int a[200];

void multi(int x)
{
    for(int i=1;i<=a[0];i++)
        a[i] *= x;
    for(int i=1;i<=a[0];i++)
        a[i+1] += a[i]/10, a[i] = a[i]%10;
    while(a[a[0]+1]!=0)
        ++a[0], a[a[0]+1] = a[a[0]]/10, a[a[0]] = a[a[0]]%10; 
}

int main()
{
    int n;
    string R;
    while(cin >> R >> n)
    {
        size_t found = R.find('.');
        int x = 0;
        Sloop(it, R)
        {
            if(*it == '.')  continue;
            x = x*10+*it-'0';
        }
        if(x == 0)
        {
            printf("0\n");
            continue;
        }
#ifdef DEBUG
        printf("%d\n",x);
#endif
        memset(a, 0, sizeof(a));
        a[0] = a[1] = 1;
        for(int i=0;i<n;i++)
            multi(x);
#ifdef DEBUG
        for(int i=a[0];i>=1;i--)
            printf("%d",a[i]);
        putchar('\n');
#endif
        if(found == string::npos)
        {
            for(int i=a[0];i>=1;i--)
                printf("%d",a[i]);
            putchar('\n');
            continue;
        }
        int t = (R.size()-found-1)*n;
        string res = "";
        if(a[0] == t)
        {
            res += '.';
            for(int i=a[0];i>=1;i--)
                res += (char)(a[i]+'0');
        }else if(a[0] > t)
        {
            for(int i=a[0];i>=t+1;i--)
                res += (char)(a[i]+'0');
            res += '.';
            for(int i=t;i>=1;i--){
                res += (char)(a[i]+'0');
            }
        }else
        {
            res += '.';
            for(int i=0;i<t-a[0];i++)
                res += '0';
            for(int i=a[0];i>=1;i--)
                res += (char)(a[i]+'0');
        }
        char c = res[res.size()-1];
        while(c == '0' || c == '.'){
            
            res = res.substr(0,res.size()-1);
            if(c == '.')    break;
            c = res[res.size()-1];
        }
        cout << res << endl;
    }
    return 0;
}