// Problem link: https://codeforces.com/problemset/problem/1648/A
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define pipii pair<int, pair<int, int>>
#define plpii pair<ll, pair<int, int>>
#define plpll pair<ll, pair<ll, ll>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
//const ll mod = 998244353;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

void zahid(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n, m; cin >> n >> m;
    vvll rows(1e5 + 1), cols(1e5 + 1), pre_rows(1e5 + 1), pre_cols(1e5 + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ll c; cin >> c;
            rows[c].pb(i); 
            cols[c].pb(j);
            pre_rows[c].pb(i); 
            pre_cols[c].pb(j);
        }
    }
    for(int i = 1; i <= 1e5; i++){
        sort(rows[i].begin(), rows[i].end());
        sort(cols[i].begin(), cols[i].end());
        sort(pre_rows[i].begin(), pre_rows[i].end());
        sort(pre_cols[i].begin(), pre_cols[i].end());
    }
    ll sum = 0;
    for(int i = 1; i <= 1e5; i++){
        if(pre_rows[i].size() > 1){
            for(int j = 1; j < pre_rows[i].size(); j++){
                pre_rows[i][j] += pre_rows[i][j - 1];
                pre_cols[i][j] += pre_cols[i][j - 1];
                sum += ((ll)j * rows[i][j]) - pre_rows[i][j - 1];
                sum += ((ll)j * cols[i][j]) - pre_cols[i][j - 1];
            }
        }
    }
    cout << sum << '\n';
}
