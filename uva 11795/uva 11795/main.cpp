//
//  main.cpp
//  uva 11795
//
//  Created by wangyijun on 14-1-25.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;
#define N (1<<16)+10
int weapon[N];
int state[N];
char s[30];
int dp[N];

int main(int argc, const char * argv[])
{
    int n;
    cin>>n;
    memset(weapon, 0, sizeof(weapon));
    memset(state, 0, sizeof(state));
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<=n; i++) {
        cin>>s;
        for (int j=0; j<strlen(s); j++) {
            if (s[i]-'0'!=0) {
                weapon[i]|=j;
            }
        }
    }
    state[0]=weapon[0];
    for (int i=1; i<(1<<n); i++) {
        state[i]=weapon[0];
        for (int j=1; i<=n; i++) {
            if(i & (1<<(j-1)))
            {
                state[i]|=weapon[j];
            }
        }
    }
    dp[0]=1;
    for (int i=1; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            if ((i&(1<<j)) && (state[i^(1<<j)]&(1<<j)) ) {
                dp[i]+=dp[i^(1<<j)];
            }
        }
        
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
    
}

