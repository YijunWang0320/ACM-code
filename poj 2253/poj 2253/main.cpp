//
//  main.cpp
//  poj 2253
//
//  Created by wangyijun on 14-5-15.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
#define INF 1000000000

double dis[205];
bool vis[205];

struct node{
    double x;
    double y;
}nodes[205];

double distance(node a,node b)
{
    double x=a.x-b.x;
    double y=a.y-b.y;
    return sqrt(x*x+y*y);
}
double min(double a,double b)
{
    if(a>b)
        return b;
    else
        return a;
}
double max(double a,double b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    int c=0;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>nodes[i].x>>nodes[i].y;
        }
        for(int i=1;i<=n;i++)
        {
            dis[i]=INF;
        }
        memset(vis, 0, sizeof(vis));
        dis[1]=0.0;
        
        for (int i=1; i<=n; i++) {
            int k=0;
            for (int j=1; j<=n; j++) {
                if (!vis[j] && dis[j]<dis[k]) {
                    k=j;
                }
            }
            if (k==0) {
                break;
            }
            vis[k]=true;
            for (int j=1; j<=n; j++) {
                if(!vis[j])
                    dis[j]=min(dis[j],max(dis[k],distance(nodes[k],nodes[j])));
            }
        }
        cout<<"Scenario #"<<++c<<endl;
        cout<<"Frog Distance = "<<dis[2]<<endl;
    }
    return 0;
}

