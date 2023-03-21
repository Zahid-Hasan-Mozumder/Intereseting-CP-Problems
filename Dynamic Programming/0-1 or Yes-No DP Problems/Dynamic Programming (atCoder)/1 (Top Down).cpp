// Problem link: https://atcoder.jp/contests/dp/tasks/dp_a
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

vll h(1e6, 0), dp(1e6, -1);

ll depression(int n){
    if(n == 1 || n == 2) return dp[n];
    if(dp[n] != -1) return dp[n];
    return dp[n] = min(abs(h[n] - h[n-1]) + depression(n-1), 
                       abs(h[n] - h[n-2]) + depression(n-2));
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>h[i];
    dp[1] = 0; 
    dp[2] = abs(h[1] - h[2]);
    depression(n);
    cout<< dp[n] << '\n';
}
