#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    int last_data;
    Node* next;
    Node* prev;
};



int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        Node* head = new Node;
        Node* p;
        scanf("%d",& head->data);
        head->last_data = head->data;
        head->next = NULL;
        head->prev = NULL;
        p = head;
        for(int i=1;i<n;i++)
        {
            Node* q = new Node;
            scanf("%d", &(q->data));
            q->last_data = q->data;
            q->next = NULL;
            q->prev = p;
            p->next = q;
            p = q;
        }
        if(n == 1){
            printf("0 %d\n", head->data);
            free(head);
            continue;
        }
        p->next = head;
        head->prev = p;
        bool flag = false;
        int cnt = 0;
        while(!flag)
        {
            cnt ++;
            flag = true;
            p = head;
            int x = -1;
            do
            {
                p->data = p->last_data/2+p->prev->last_data/2;
                if(p->data & 1)  p->data++;
                if(x == -1)
                {
                    x = p->data;
                }else{
                    if(p->data != x)
                        flag = false;
                }
                p = p->next;
            }while(p!=head);
            p = head;
            do
            {
                p->last_data = p->data;
                p = p->next;
            }while(p!=head);
        }
        printf("%d %d\n", cnt, head->data);
        Node* x;
        Node* y;
        x = head->next;
        y = head->next->next;
        while(y!=head)
        {
            free(x);
            x = y;
            y = y->next;
        }
        free(x);
        free(head);

    }
    return 0;
}
