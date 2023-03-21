// Problem link: https://atcoder.jp/contests/dp/tasks/dp_c
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>
#define vvll vector<vector<ll>>

vll a(1e5+5, 0), b(1e5+5, 0), c(1e5+5, 0);
vvll dp(1e5+5, vll(3, 0));

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    dp[1][0] = a[1]; dp[1][1] = b[1]; dp[1][2] = c[1];
    for(int i=2; i<=n; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }
    cout<< max(max(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
}
