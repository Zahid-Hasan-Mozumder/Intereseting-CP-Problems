// Problem link: https://atcoder.jp/contests/dp/tasks/dp_d
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>
#define vvll vector<vector<ll>>

ll n, ks;
vll w(1e5+5), c(1e5+5);
vvll dp(105, vll(1e5+5, 0));

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
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= ks; j++){
            if(j < w[i]) 
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + c[i]);
        }
    }
    cout<< dp[n][ks] << '\n';
}
