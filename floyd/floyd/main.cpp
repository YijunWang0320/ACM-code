//
//  main.cpp
//  floyd
//
//  Created by wangyijun on 13-11-17.
//  Copyright (c) 2013年 wangyijun. All rights reserved.
//

#include <iostream>
using namespace std;
#define INF 1000001
int main(int argc, const char * argv[])
{
    int n,m;
    cin>>n;
    cin>>m;
    int d[100][100];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            d[i][j]=INF;
        }
        d[i][i]=0;
    }
    int x,y,w;
    for (int k=0; k<m; k++) {
        cin>>x>>y>>w;
        d[x][y]=w;
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (d[i][k]<INF && d[k][j]<INF && d[i][j]>d[i][k]+d[k][j]) {
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
}

