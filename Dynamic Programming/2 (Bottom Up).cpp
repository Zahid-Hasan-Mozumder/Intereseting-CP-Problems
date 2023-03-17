// Problem link: https://atcoder.jp/contests/dp/tasks/dp_b
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

vll h(1e6, 0), dp(1e6, LLONG_MAX);
int n, k;

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
    for(int i=2; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i - j < 1) break;
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout<< dp[n] << '\n';
}
