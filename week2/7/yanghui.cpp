#include<bits/stdc++.h>
#include "SeqQueue.h"
using namespace std;
/*
1
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
*/

int main()
{
    SeqQueue<int>que;
    int n;
    cin >> n;
    que.EnQueue(0);
    que.EnQueue(1);
    que.EnQueue(0);
    if(n!=0) cout << 1 <<endl;
    int e1,e2,tmp;
    for(int i=2;i<=n;++i){
        for(int j=1;j<=i;++j){
            que.DelQueue(e1);
            que.GetHead(e2);
            tmp += (e1+e2);
            cout << tmp <<" ";
            que.EnQueue(tmp);
            tmp = 0;
        }
        que.EnQueue(0);
        cout << endl;
    }
    return 0;
}
