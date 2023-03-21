// Problem link: https://cses.fi/problemset/task/1633/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

const ll mod = 1e9+7;

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin>>n;
    vi dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0){
                dp[i] = dp[i] + dp[i - j];
                dp[i] %= mod;
            }
        }
    }
    cout<< dp[n] << '\n';
}
