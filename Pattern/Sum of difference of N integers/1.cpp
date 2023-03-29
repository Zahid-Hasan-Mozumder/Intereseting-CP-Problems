// Problem link: https://codeforces.com/contest/1808/problem/B
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin>>t;
    while(t--){
        ll n, m; cin >> n >> m;
        vvll a(m, vll(n));
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                cin>>a[i][j];
            }
        }
        for(int i = 0; i < m; i++){
            sort(a[i].begin(), a[i].end());
        }
        ll ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                ans += (j * (n - j)) * (a[i][j] - a[i][j - 1]);
            }
        }
        cout<< ans << '\n';
    }
}
