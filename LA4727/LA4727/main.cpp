//
//  main.cpp
//  LA4727
//
//  Created by wangyijun on 14-1-25.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
using namespace std;
int f[500000];
int main(int argc, const char * argv[])
{
    int n,k;
    cin>>n>>k;
    int ans1=0,ans2,ans3;
    for (int i=2; i<=n; i++) {
        ans1=(ans1+k)%i;
        if(i==2)
        {
            ans2=!ans1;
        }
        else if(i==3)
        {
            ans2=(ans2+k)%i;
            int v[3];
            memset(v, 0,sizeof(v));
            v[ans1]=1;
            v[ans2]=1;
            for (int i=0; i<3; i++) {
                if (v[i]==0) {
                    ans3=i;
                }
            }
        }
        else
        {
            ans2=(ans2+k)%i;
            ans3=(ans3+k)%i;
        }
    }
    cout<<ans1+1<<endl;
    cout<<ans2+1<<endl;
    cout<<ans3+1<<endl;
    return 0;
}

