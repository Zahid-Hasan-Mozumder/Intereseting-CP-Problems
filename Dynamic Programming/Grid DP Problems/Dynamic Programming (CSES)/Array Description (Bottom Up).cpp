// Problem link: https://cses.fi/problemset/task/1746/
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

const int mod = 1e9+7;

int n, k;
vi a(1e5+2);
vvi dp(1e2+2, vi(1e5+2, 0));

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= n; j++){
        if(j == 1){
            if(a[j] == 0){
                for(int i = 1; i <= k; i++){
                    dp[i][j] = 1;
                }
            }
            else{
                dp[a[j]][j] = 1;
            }
        }
        else{
            if(a[j] == 0){
                for(int i = 1; i <= k; i++){
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j] %= mod;
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                    dp[i][j] += dp[i+1][j-1];
                    dp[i][j] %= mod;
                }
            }
            else{
                dp[a[j]][j] += dp[a[j]-1][j-1];
                dp[a[j]][j] %= mod;
                dp[a[j]][j] += dp[a[j]][j-1];
                dp[a[j]][j] %= mod;
                dp[a[j]][j] += dp[a[j]+1][j-1];
                dp[a[j]][j] %= mod;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= k; i++){
        ans += dp[i][n];
        ans %= mod;
    }
    cout<< ans << '\n';
}
