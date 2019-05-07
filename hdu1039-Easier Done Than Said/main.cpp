#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int is_vowel(char ch)
{
    char vowels[] = {'a','e','i','o','u'};
    for(int i=0;i<5;i++)
        if(ch == vowels[i]) return 1;
    return 0;
}

int contain_three(char* st)
{
    int cnt = -1;
    if(is_vowel(st[0])) cnt = 1;
    for(int i=1;i<strlen(st);i++)
    {
        if(cnt>0 && is_vowel(st[i]))    cnt ++;
        else if(cnt>0 && !is_vowel(st[i]))   cnt = -1;
        else if(cnt<0 && is_vowel(st[i]))   cnt = 1;
        else if(cnt<0 && !is_vowel(st[i]))  cnt --;
        if(cnt == 3 || cnt == -3)    return true;
    }
    return false;
}

int two_ch(char* st)
{
    for(int i=1;i<strlen(st);i++)
        if(st[i] == st[i-1] && (st[i]!='e' && st[i]!='o'))    return true;
    return false;
}

int main()
{
    char st[21];
    while(scanf("%st",st) && strcmp(st,"end"))
    {
        bool flag_1 = false;
        // 至少一个元音字母
        for(int i=0;i<strlen(st);i++)
            if(is_vowel(st[i]))
            {
                flag_1 = true;
                break;
            }
        if(!flag_1){
            printf("<%s> is not acceptable.\n", st);
            continue;
        }
        // 不包含3个连续的元音或三个连续的辅音
        if(contain_three(st)){
            printf("<%s> is not acceptable.\n", st);
            continue;
        }
        //不包含连续字母
        if(two_ch(st)){
            printf("<%s> is not acceptable.\n", st);
            continue;
        }
        printf("<%s> is acceptable.\n", st);
    }
    return 0;
}
