// Problem link: https://atcoder.jp/contests/dp/tasks/dp_e
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define vvll vector<vector<ll>>

ll n, ks;
vll w(105), val(105);
vvll dp(105, vll(1e5+5, -1));

ll depression(ll v, ll i){
    if(v == 0) return 0;
    if(i < 1) return 1e18;
    if(dp[i][v] != -1) return dp[i][v];
    ll weight = depression(v, i - 1);
    if(v >= val[i])
        weight = min(weight, depression(v - val[i], i - 1) + w[i]);
    return dp[i][v] = weight;
}

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
    ll ans = INT_MIN;
    for(int i = 1e5; i >= 0; i--){
        if(depression(i, n) <= ks){
            ans = max(ans, (ll)i);
        }
    }
    cout << ans << '\n';
}
