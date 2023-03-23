// Problem link: https://cses.fi/problemset/task/1145
// Disadvantage : TLE for big contraints like n > 10^4
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

const int sz = 1e6+2;

vector<int> a(sz);
vector<int> dp(sz, 1);

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout<< ans << '\n';
}
