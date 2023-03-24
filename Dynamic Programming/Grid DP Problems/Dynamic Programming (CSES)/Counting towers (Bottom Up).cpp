// Problem link: https://cses.fi/problemset/task/2413/
// Helpful video: https://www.youtube.com/watch?v=51AkVn5Urno
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define vvll vector<vector<ll>>

const int mod = 1e9+7;

vvll dp(2, vll(1e6+2, 0));
void depression(){
    dp[0][1] = 1; dp[1][1] = 1;
    for(int i = 2; i < 1e6+2; i++){
        dp[0][i] += (((dp[0][i-1] * 4) % mod) + (dp[1][i-1] % mod)) % mod;
        dp[1][i] += ((dp[0][i-1] % mod) + ((dp[1][i-1] * 2) % mod)) % mod;
    }
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();
    depression();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout<< ((dp[0][n] % mod) + (dp[1][n] % mod)) % mod << '\n';
    }
}
