// Problem link: https://atcoder.jp/contests/dp/tasks/dp_b
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

vll h(1e6, 0), dp(1e6, LLONG_MAX);
int n, k;

ll depression(int i){
    if(i < 1) return 0;
    if(dp[i] != LLONG_MAX) return dp[i];
    for(int j=1; j<=k; j++){
        if(i - j > 0) dp[i] = min(dp[i], depression(i - j) + abs(h[i] - h[i - j]));
    }
    return dp[i];
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>h[i];
    dp[1] = 0;
    depression(n);
    cout<< dp[n] << '\n';
}
