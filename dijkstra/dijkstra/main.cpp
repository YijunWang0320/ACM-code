//
//  main.cpp
//  dijkstra
//
//  Created by wangyijun on 13-11-15.
//  Copyright (c) 2013年 wangyijun. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define N 100
#define INF 100000
int findit(int *d,bool *vis,int n)
{
    int min=INF;
    int number;
    for (int i=0; i<n; i++)
        if (vis[i]!=1 && min>d[i]) {
            min=d[i];
            number=i;
        }
    return number;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int main(int argc, const char * argv[])
{
    int d[N];
    int n,m;
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        d[i]=INF;
    }
    
    d[0]=0;
    int a,b,length;
    int e[100][100];
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        cin>>length;
        e[a][b]=length;
    }
    for (int i=1; i<n; i++) {
        if (e[0][i]!=0) {
            d[i]=e[0][i];
        }
    }
    
    bool vis[100];
    memset(vis, 0, sizeof(vis));
    vis[0]=true;
    
    
    for (int i=1; i<n; i++) {
        int x=findit(d, vis, n);
        
        vis[x]=1;
        for (int j=0; j<n; j++) {
            if (!vis[j] && e[x][j]!=0) {
                d[j]=min(d[j],d[x]+e[x][j]);
            }
        }
        
    }
    for (int i=0; i<n; i++) {
        cout<<d[i]<<" ";
        cout<<endl;
    }
    
}

