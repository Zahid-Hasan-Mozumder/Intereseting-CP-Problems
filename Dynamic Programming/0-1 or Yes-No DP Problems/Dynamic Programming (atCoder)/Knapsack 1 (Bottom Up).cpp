// Problem link: https://atcoder.jp/contests/dp/tasks/dp_d
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

ll n, ks;
vll w(105), val(105);
vll dp(1e5+5, -1e18);

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> n >> ks;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> val[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = ks; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
        }
    }
    ll ans = INT_MIN;
    for(int i = ks; i >= 0; i--){
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}
