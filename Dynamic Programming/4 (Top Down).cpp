// Problem link: https://atcoder.jp/contests/dp/tasks/dp_d
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>
#define vvll vector<vector<ll>>

ll n, ks;
vll w(1e5+5), c(1e5+5);
vvll dp(105, vll(1e5+5, -1));

ll depression(ll i, ll wt){
    if(i == 0 || wt == 0) return 0;
    if(dp[i][wt] != -1) return dp[i][wt];
    ll mx = LLONG_MIN;
    mx = max(mx, depression(i-1, wt));
    if(wt >= w[i]) 
        mx = max(mx, depression(i-1, wt - w[i]) + c[i]);
    dp[i][wt] = mx;
    return dp[i][wt];
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
        cin >> w[i] >> c[i];
    }
    cout<< depression(n, ks) << '\n';
}
