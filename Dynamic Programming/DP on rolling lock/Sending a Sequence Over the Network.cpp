// Problem link: https://codeforces.com/contest/1741/problem/E
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi a(n + 1);
        vb dp(n + 1, false);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            if(i + a[i] <= n) dp[i + a[i]] = (dp[i + a[i]] | dp[i - 1]);
            if(i - a[i] - 1 >= 0) dp[i] = (dp[i] | dp[i - a[i] - 1]);
        }
        if(dp[n]) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
