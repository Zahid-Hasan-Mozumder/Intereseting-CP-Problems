// Problem link: https://atcoder.jp/contests/dp/tasks/dp_a
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin>>n;
    vll h(n), dp(n, 0);
    for(int i=0; i<n; i++) cin>>h[i];
    for(int i=1; i<n; i++){
        if(i == 1) 
            dp[i] = dp[i-1] + abs(h[i] - h[i-1]);
        else 
            dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }
    cout<< dp[n-1] << '\n';
}
