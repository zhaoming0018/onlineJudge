#include <iostream>
#include <string>
using namespace std;

struct point{
    int x;
    int y;
    int flag;
    point(int a, int b):
        x(a), y(b){}
};

int dx[4] = {10,0,-10,0}, dy[4] = {0,-10,0,10};

int change_dir(int cur, char com)
{
    return com=='V'?(cur+3)%4:(cur+1)%4;
}

int main()
{
    string st;
    while(cin >> st)
    {
        cout << "300 420 moveto" << endl;
        cout << "310 420 lineto" << endl;
        point p = point(310,420);
        p.flag = 0;
        for(int i=0;i<st.size();i++)
        {
            char ch = st.at(i);
            p.flag = change_dir(p.flag, ch);
            // move
            p.x += dx[p.flag];
            p.y += dy[p.flag];
            cout << p.x << " " << p.y << " lineto" << endl;
        }
        cout << "stroke" << endl << "showpage" << endl;
    }
    return 0;
}
