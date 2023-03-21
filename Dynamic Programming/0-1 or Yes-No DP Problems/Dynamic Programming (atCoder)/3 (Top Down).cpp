// Problem link: https://atcoder.jp/contests/dp/tasks/dp_c
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>
#define vvll vector<vector<ll>>

vll a(1e5+5, 0), b(1e5+5, 0), c(1e5+5, 0);
vvll dp(1e5+5, vll(3, -1));

ll depression(int i, int j){
    if(i == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(j == 0) dp[i][j] = max(depression(i-1, 1), depression(i-1, 2)) + a[i];
    if(j == 1) dp[i][j] = max(depression(i-1, 0), depression(i-1, 2)) + b[i];
    if(j == 2) dp[i][j] = max(depression(i-1, 0), depression(i-1, 1)) + c[i];
    return dp[i][j];
}

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
    cout<< max(max(depression(n, 0), depression(n, 1)), depression(n, 2)) << '\n';
}
