//
//  main.cpp
//  BFS_Flow
//
//  Created by wangyijun on 13-11-17.
//  Copyright (c) 2013年 wangyijun. All rights reserved.
//

#include <iostream>
#include <queue>
#define N 100
#define INF 100001
using namespace std;
int main(int argc, const char * argv[])
{
    int n,m;
    cin>>n>>m;
    queue<int> myQueue;
    int cap[N][N],flow[N][N],p[N];
    //initiate
  /*  for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>cap[i][j];
        }
    }*/
    memset(cap, 0, sizeof(cap));
    for (int i=0; i<m; i++) {
        int x,y,w;
        cin>>x>>y>>w;
        cap[x][y]=w;
    }
    int s,t,f;
    f=0;
    cin>>s>>t;
    memset(flow, 0, sizeof(flow));
    while (true) {
        int a[N];
        memset(a, 0, sizeof(a));
        myQueue.push(s);
        a[s]=INF;
        while (!myQueue.empty()) {
            int u=myQueue.front();
            myQueue.pop();
            for (int v=0; v<n; v++) {
                if (!a[v] && cap[u][v]>flow[u][v]) {
                    p[v]=u;
                    myQueue.push(v);
                    a[v]=min(a[u], cap[u][v]-flow[u][v]);
                }
            }
        }
        if (a[t]==0) {
            break;
        }
        for (int i=t; i!=s; i=p[i]) {
            flow[p[i]][i]+=a[t];
            flow[i][p[i]]-=a[t];
        }
        f+=a[t];
        
    }
    cout<<f<<endl;
    return 0;
}

