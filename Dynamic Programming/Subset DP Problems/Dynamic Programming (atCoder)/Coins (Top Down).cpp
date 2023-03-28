// Problem link: https://atcoder.jp/contests/dp/tasks/dp_i
// Editorial video: https://www.youtube.com/watch?v=HP_gftgDoIo
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int n;
vector<double> p(3001, 0);
vector<vector<double>> dp(3001, vector<double>(3001, -1));

double depression(int i, int total_head){
    if(i == n){
        if(total_head > (n - total_head)) return 1.0;
        else return 0.0;
    }
    if(dp[i][total_head] != -1) return dp[i][total_head];
    double h = p[i] * depression(i + 1, total_head + 1);
    double t = (1.0 - p[i]) * depression(i + 1, total_head);
    return dp[i][total_head] = h + t;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    cout << fixed << setprecision(9) << depression(0, 0) << '\n';
}
