// Problem link: https://cses.fi/problemset/task/1746/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

const int mod = 1e9+7;

int n, k;
vi a(1e5+2);
vvi dp(1e2+2, vi(1e5+2, -1));

int depression(int x, int i){
    if(i == 1){
        if(a[i] == 0) return dp[x][i] = 1;
        else{
            if(a[i] == x) return dp[x][i] = 1;
            else return dp[x][i] = 0;
        }
    }
    if(dp[x][i] != -1) return dp[x][i];
    if(a[i] != 0 && x != a[i]) return dp[x][i] = 0;
    
    int ans = 0;
    if(x - 1 > 0){
        ans += depression(x - 1, i - 1);
        ans %= mod;
    }
    ans += depression(x, i - 1);
    ans %= mod;
    if(x + 1 <= k){
        ans += depression(x + 1, i - 1);
        ans %= mod;
    }
    return dp[x][i] = ans;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= k; i++){
        ans += depression(i, n);
        ans %= mod;
    }
    cout << ans << '\n';
}
