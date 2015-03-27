//
//  main.cpp
//  uva11134
//
//  Created by wangyijun on 13-11-19.
//  Copyright (c) 2013年 wangyijun. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define N 5000
int n;
struct node {
    int id,l,r;
    friend bool operator< (const node &u,const node &v)
    {
          if(u.l<v.l)
              return true;
          else if(u.l==v.l)
              return u.r<v.r;
          else
              return false;
    }
}x[N],y[N];
int vis[N][2];
int max(int a,int b)
{
    return a>b?a:b;
}
int check(int pos)
{
    int maxx=0;
    priority_queue<node> q;
    if (pos==0) {
        for (int i=0; i<n; i++) {
            q.push(x[i]);
        }
    }
    else
    {
        for (int i=0; i<n; i++) {
            q.push(y[i]);
        }
    }
    while (!q.empty()) {
        node cur=q.top();
        q.pop();
        if (maxx>cur.r) {
            return false;
        }
        if (maxx>cur.l) {
            cur.l=maxx;
            q.push(cur);
            continue;
        }
        vis[cur.id][pos]=max(cur.l,maxx);
        maxx=max(cur.l, maxx);
    }
    return true;
    
}
int main(int argc, const char * argv[])
{
    memset(vis, 0, sizeof(vis));
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>x[i].l>>x[i].r>>y[i].l>>y[i].r;
        x[i].id=i;
        y[i].id=i;
    }
    if(check(1) && check(0))
    {
        for (int i=0; i<n; i++) {
            cout<<vis[i][0]<<" "<<vis[i][1]<<endl;
        }
    }
    else{
        cout<<"impossible"<<endl;
    }

}

