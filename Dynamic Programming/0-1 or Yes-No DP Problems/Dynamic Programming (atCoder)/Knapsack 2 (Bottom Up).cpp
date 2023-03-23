// Problem link: https://atcoder.jp/contests/dp/tasks/dp_e
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

ll n, ks;
vll w(105), val(105);
vll dp(1e5+5, 1e18);

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
        for(int j = 1e5; j >= val[i]; j--){
            dp[j] = min(dp[j], dp[j - val[i]] + w[i]);
        }
    }
    ll ans = INT_MIN;
    for(int i = 1e5; i >= 0; i--){
        if(dp[i] <= ks)
            ans = max(ans, (ll)i);
    }
    cout << ans << '\n';
}
