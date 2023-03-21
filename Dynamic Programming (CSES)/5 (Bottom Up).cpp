// Problem link: https://cses.fi/problemset/task/1637/
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back

const int sz = 1e6+2;
vi dp(sz, 1e9);

vi generateDigits(int x){
    vi digits;
    while(x){
        if(x % 10 != 0) digits.pb(x % 10);
        x /= 10;
    }
    return digits;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin >> n;
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        vi digits = generateDigits(i);
        for(int j = 0; j < digits.size(); j++){
            if(i - digits[j] >= 0){
                dp[i] = min(dp[i], dp[i - digits[j]] + 1);
            }
        }
    }
    cout << dp[n] << '\n';
}
