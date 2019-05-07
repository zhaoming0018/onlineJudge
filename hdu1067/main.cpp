#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

int a[4][8];

string target;
struct Node{
    int step;
    string key;
};

queue<Node> q;
set<string> table;


void find_pos(Node p, int pos[4])
{
    int k = 0;
    for(int i=0;i<32;i++)
    {
        if(p.key[i] == (char)1)
        {
            pos[k++] = i;
            if(k == 4)  return;
        }
    }
}


int find_next(Node p, char x)
{
    if(x % 10 == 7) return -1;
    if(x == 1)  return -1;
    for(int i=0;i<32;i++)
        if(p.key[i] == x+1)  return i;
}

int bfs()
{
    while(!q.empty())   q.pop();
    while(!table.empty())   table.clear();
    Node tmp;
    tmp.step = 0;
    tmp.key = "";
    for(int i=0;i<4;i++)
    for(int j=0;j<8;j++)
        tmp.key += (char)a[i][j];
    if(tmp.key == target) return 0;
    table.insert(tmp.key);
    q.push(tmp);
    while(!q.empty())
    {
        Node p = q.front();
        q.pop();
        int pos[4];
        find_pos(p, pos);
        for(int i=0;i<4;i++)
        {
            int t = find_next(p,p.key[pos[i]-1]);
            if(t == -1) continue;
            tmp.key = p.key;
            tmp.key[pos[i]] = tmp.key[pos[i]-1]+1;
            tmp.key[t] = 1;
            tmp.step = p.step+1;
            if(table.count(tmp.key))   continue;
            table.insert(tmp.key);
            if(tmp.key == target)   return tmp.step;
            q.push(tmp);
        }
    }
    return -1;
}

void init()
{
    target = "";
    for(int i=1;i<=4;i++)
    {
        for(char j=i*10+1;j<=i*10+7;j++)
            target += j;
        target += (char)1;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    init();
    int n;
    scanf("%d",&n);
    while(n--)
    {
        a[0][0] = 11, a[1][0] = 21, a[2][0] =31, a[3][0] = 41;
        for(int i=0;i<4;i++)
        for(int j=1;j<=7;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]%10 == 1) a[i][j] = 1;
        }
        printf("%d\n",bfs());
    }
    return 0;
}