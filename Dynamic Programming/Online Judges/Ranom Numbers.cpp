// Problem link: https://codeforces.com/contest/1841/problem/C
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

string s;
vvvll dp;

ll val(char x){
    if(x == 'A') return 1;
    if(x == 'B') return 10;
    if(x == 'C') return 100;
    if(x == 'D') return 1000;
    if(x == 'E') return 10000;
}

ll depression(int i, int cng, char mx){
    if(i < 0) return 0;
    if(dp[i][mx - 'A'][cng] != -1) return dp[i][mx - 'A'][cng];
    
    ll res = LLONG_MIN;
    ll curr = val(s[i]);
    if(s[i] < mx) res = max(res, depression(i - 1, cng, mx) - curr);
    else res = max(res, depression(i - 1, cng, s[i]) + curr);
    if(!cng){
        for(int j = 0; j < 5; j++){
            ll currr = val('A' + j);
            if(j < mx - 'A') 
                res = max(res, depression(i - 1, cng ^ 1, mx) - currr);
            else 
                res = max(res, depression(i - 1, cng ^ 1, 'A' + j) + currr);
        }
    }
    return dp[i][mx - 'A'][cng] = res;
}

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

    int t; cin >> t;
    while(t--){
        cin >> s;
        int n = s.size();
        dp.clear();
        dp.resize(n + 1, vvll(5, vll(2, -1)));
        ll ans = depression(n - 1, 0, 'A');
        cout << ans << '\n';
    }
}
