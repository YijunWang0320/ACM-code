//
//  main.cpp
//  uva11134 fabled rooks
//
//  Created by wangyijun on 14-1-2.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct rook
{
    int l,r,id;
    bool operator < (rook b) const
    {
        return r>b.r;
    }
}x[5000],y[5000];
int finalX[5000],finalY[5000];
int n;
bool cmp(const rook &a,const rook &b)
{
    return a.l<b.l;
}
bool process()
{
    sort(x, x+n, cmp);
    sort(y, y+n, cmp);
    priority_queue<rook> Qx;
    priority_queue<rook> Qy;
    int kx=0,ky=0;
    for (int i=0; i<n; i++) {
        while (x[kx].l<=i && kx<n) {
            Qx.push(x[kx++]);
        }
        if (Qx.empty()) {
            return false;
        }
            rook temp=Qx.top();
            Qx.pop();
            if (temp.r<i)
                return false;
            finalX[i]=temp.id;
    }
    for (int j=0; j<n; j++) {
        while (y[ky].l<=j && ky<n) {
            Qy.push(y[ky++]);
        }
        if (Qy.empty()) {
            return false;
        }
            rook temp=Qy.top();
            Qy.pop();
            if (temp.r<j) {
                return false;
            }
            finalY[j]=temp.id;
        
    }
    return true;
}
int main(int argc, const char * argv[])
{
    cin>>n;
    for (int i=0;i<n; i++) {
        cin>>x[i].l>>x[i].r;
        cin>>y[i].l>>y[i].r;
        x[i].id=i;
        y[i].id=i;
    }
    if(!process())
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
}

