#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <string>
#define MAXN 362888
#include <ctype.h>
using namespace std;
char chs[10], ch;
bool visited[MAXN];
string str[MAXN];

int dx[4] = {0,0,1,-1}, dy[4]={1,-1,0,0};
int fac[] = {1,1,2,6,24,120,720,5040,40320};
char st[] = {'l','r','u','d'};

struct Node
{
    int xx;
    int hash_value;
    char eight[10];
};
queue<Node> q;

bool can_move(Node p, int i)
{
    int pos = p.xx;
    int tmp_x = pos/3+dx[i];
    int tmp_y = pos%3+dy[i];
    if(tmp_x >= 0 && tmp_x < 3 && tmp_y >=0 && tmp_y <3)
        return true;
    return false;
}

int get_hash(Node p)
{
    int ans = 0;
    for(int i=0;i<9;i++)
    {
        int x=0;
        for(int j=i+1;j<9;j++)
            if(p.eight[j] < p.eight[i])   x++;
        ans += x*fac[8-i];
    }
    return ans;
}

Node new_node(Node p, int i)
{
    Node new_p;
    int pos = p.xx;
    int tmp_x = pos/3+dx[i];
    int tmp_y = pos%3+dy[i];
    int tmp = tmp_x*3+tmp_y;
    strcpy(new_p.eight, p.eight);
    new_p.eight[pos] = p.eight[tmp];
    new_p.eight[tmp] = p.eight[pos];
    new_p.xx = tmp;
    new_p.hash_value = get_hash(new_p);
    return new_p;
}

void bfs()
{
    Node node0;
    strcpy(node0.eight, "12345678x");
    node0.hash_value = get_hash(node0);
    node0.xx = 8;
    visited[node0.hash_value] = true;
    str[node0.hash_value] = "";
    while(!q.empty())   q.pop();
    q.push(node0);
    while(!q.empty())
    {
        Node p = q.front();
        int hash_p = p.hash_value;
        for(int i=0;i<4;i++)
        {
            if(!can_move(p,i))  continue;
            Node new_p = new_node(p, i);
            int hash_new = new_p.hash_value;
            if(!visited[hash_new])
            {
                q.push(new_p);
                visited[hash_new] = true;
                str[hash_new] = str[hash_p] + st[i];
            }
        }
        q.pop();
    }
}

char get_one_char()
{
    char ch = getchar();
    while((ch==' ' || ch == '\n')&& ch!=EOF)
        ch = getchar();
    return ch;
}

int main()
{
    freopen("in.txt", "r", stdin);
    memset(visited, 0, sizeof(visited));
    bfs();
    while((chs[0] = get_one_char())!=EOF)
    {
        for(int i=1;i<=8;i++)
            chs[i] = get_one_char();
        chs[9] = '\0';
        Node p;
        strcpy(p.eight, chs);
        int hash_p = get_hash(p);
        if(!visited[hash_p]){
            printf("unsolvable\n");
            continue;
        }
        string s = str[hash_p];
        for(int i=s.length()-1;i>=0;i--)
            printf("%c", s[i]);
        putchar('\n');
    }
    return 0;
}
