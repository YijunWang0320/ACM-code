//
//  main.cpp
//  dijkstra<g>
//
//  Created by wangyijun on 13-11-15.
//  Copyright (c) 2013年 wangyijun. All rights reserved.
//

#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define MAXN 100
#define INF 100000
int main(int argc, const char * argv[])
{
    int n,m;
    cin>>n>>m;
    int first[MAXN];
    int u[MAXN],next[MAXN],v[MAXN],w[MAXN],d[MAXN];
    for (int i=0; i<n; i++) {
        first[i]=-1;
        d[i]=(i==0?0:INF);
    }
    for (int i=0; i<m; i++) {
        cin>>u[i]>>v[i]>>w[i];
        next[i]=first[u[i]];
        first[u[i]]=i;
    }
    typedef pair<int, int> pi;
    priority_queue<pi,vector<pi>,greater<pi> > myQueue;
    bool done[MAXN];
    memset(done, 0, sizeof(done));
    myQueue.push(make_pair(d[0], 0));
    while (!myQueue.empty()) {
        pi u=myQueue.top();
        myQueue.pop();
        int x=u.second;
        if (done[x]) {
            continue;
        }
        done[x]=true;
        for (int e=first[x]; e!=-1; e=next[e]) {
            if (d[v[e]]>d[x]+w[e]) {
                d[v[e]]=d[x]+w[e];
                myQueue.push(make_pair(d[v[e]], v[e]));
            }
        }
    }
    for (int i=0; i<n; i++) {
        cout<<d[i]<<" "<<endl;
    }
    
    
}

