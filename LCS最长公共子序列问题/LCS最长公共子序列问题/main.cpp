//
//  main.cpp
//  LCS最长公共子序列问题
//
//  Created by wangyijun on 14-1-2.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
using namespace std;
int a[1000];
int b[1000];
int d[1000][1000];
int an,bn;
int main(int argc, const char * argv[])
{
    cin>>an>>bn;
    memset(d, 0, sizeof(d));
    for (int i=1; i<=an; i++) {
        cin>>a[i];
    }
    for (int i=1; i<=bn; i++) {
        cin>>b[i];
    }
    for (int i=1; i<=an; i++) {
        for (int j=1; j<=bn; j++) {
            if (a[i]==b[j]) {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i][j-1],d[i-1][j]);
            }
        }
    }
    cout<<d[an][bn]<<endl;
    return 0;
}

