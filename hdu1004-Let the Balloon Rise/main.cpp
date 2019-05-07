#include <iostream>
#include <string>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    map<string, int> ballon;
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        ballon.erase(ballon.begin(), ballon.end());
        string best_color;
        int x = 0;
        for(int i=0;i<n;i++)
        {
            string st;
            cin >> st;
            ballon[st] = ballon[st]+1;
            if(ballon[st]>x)
                x = ballon[st], best_color = st;
        }
        cout << best_color << endl;
        scanf("%d",&n);
    }
    return 0;
}
