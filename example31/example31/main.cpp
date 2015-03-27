//
//  main.cpp
//  example31
//
//  Created by wangyijun on 13-11-18.
//  Copyright (c) 2013年 wangyijun. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define N 10000
int d[N],q[N];
int total_weight[N],total_length[N],dis2ori[N];
int x[N],y[N],w;

int func(int i)
{
    return d[i]-total_length[i+1]+dis2ori[i+1];
    
}
int main(int argc, const char * argv[])
{
    int n,c;
    cin>>n>>c;
    total_weight[0]=total_length[0]=dis2ori[0]=d[0]=0;
    x[0]=y[0]=0;
    for (int i=1; i<=n; i++) {
        cin>>x[i]>>y[i]>>w;
        total_weight[i]=total_weight[i-1]+w;
        total_length[i]=total_length[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
        dis2ori[i]=abs(x[i])+abs(y[i]);
    }
    int front=1;
    int rear=1;
    q[1]=0;
    for (int i=1; i<=n; i++) {
        while (front<=rear && total_weight[i]-total_weight[q[front]]>c)
            front++;
    d[i]=func(q[front])+dis2ori[i]+total_length[i];
        while (front<=rear && func(i)<func(q[rear]) ) {
            rear--;
        }
        q[rear++]=i;
    
    }
   
}

