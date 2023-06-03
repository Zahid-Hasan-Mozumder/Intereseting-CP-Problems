// Problem link: https://codeforces.com/problemset/problem/1697/C
// Video Editorial: https://www.youtube.com/watch?v=5jYqkhRn80w
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string x; cin >> x;
        string y; cin >> y;
        string xx, yy;
        for(int i = 0; i < n; i++){
            if(x[i] != 'b') xx.pb(x[i]);
            if(y[i] != 'b') yy.pb(y[i]);
        }
        if(xx == yy){
            vi xa, ya, xc, yc;
            for(int i = 0; i < n; i++){
                if(x[i] == 'a') xa.pb(i);
                if(y[i] == 'a') ya.pb(i);
                if(x[i] == 'c') xc.pb(i);
                if(y[i] == 'c') yc.pb(i);
            }
            bool flag = true;
            for(int i = 0; i < xa.size(); i++){
                if(xa[i] > ya[i]) flag = false;
            }
            for(int i = 0; i < xc.size(); i++){
                if(xc[i] < yc[i]) flag = false;
            }
            if(flag) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
        else cout << "No" << '\n';
    }
}
