#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
struct record{
    char ch;
    int cnt;
};

struct{
    int len;
    record rec[100];
}alpha;

int a[100];

int find(char ch)
{
    for(int i=0;i<alpha.len;i++)
        if(ch == alpha.rec[i].ch)  return i;
    return -1;
}


int main()
{
    freopen("in.txt","r",stdin);
    string st;
    while(cin >> st && st!="END")
    {
        alpha.len = 0;
        for(int i=0;i<st.size();i++)
        {
            int pos = find(st[i]);
            if(pos == -1)
            {
                alpha.rec[alpha.len].ch = st[i];
                alpha.rec[alpha.len].cnt = 1;
                alpha.len ++;
            }else{
                alpha.rec[pos].cnt ++;
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<alpha.len;i++)
            pq.push(alpha.rec[i].cnt);
        int sum = 0;
        while(pq.size()>1)
        {
            int x = pq.top();pq.pop();
            int y = pq.top();pq.pop();
            sum += x+y;
            pq.push(x+y);
        }
        if(sum == 0)    sum = pq.top();
        printf("%d %d %.1lf\n", 8*st.length(), sum, 8.0*st.length()/sum );
    }
    
    return 0;
}