// Problem link: https://atcoder.jp/contests/dp/tasks/dp_f
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

string s, t;
vvi dp(3e3+5, vi(3e3+5, -1));

int depression(int i, int j){
    if(i == 0 || j == 0) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    int res = INT_MIN;
    res = max(depression(i - 1, j), depression(i, j - 1));
    if(s[i] == t[j]) res = max(res, depression(i - 1, j - 1) + 1);
    else res = max(res, depression(i - 1, j - 1));
    return dp[i][j] = res;
}

string generate(int i, int j){
    string ans = "";
    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i - 1][j]) i--;
        else if(dp[i][j] == dp[i][j - 1]) j--;
        else{
            ans = s[i] + ans;
            i--; j--;
        }
    }
    return ans;
}
    
void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    int n = s.size();
    int m = t.size();
    int lcs_length = depression(n - 1, m - 1);
    string lcs_string = generate(n - 1, m - 1);
    cout << lcs_string << '\n';
}
