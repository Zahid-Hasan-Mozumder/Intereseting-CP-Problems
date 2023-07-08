// Problem link: https://atcoder.jp/contests/abc309/tasks/abc309_d
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define pipll pair<int, pair<ll, ll>>
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
#define vpipll vector<pair<int, pair<ll, ll>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const int N = 2e6 + 2;
const int sz = 1e6 + 2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

int x, y, m;
vvi al;
vb vis;
vi lvl;

void bfs(int i){
    queue<pii> q;
    q.push({i, 0});
    vis[i] = true;
    while(!q.empty()){
        int curr = q.front().ff;
        int l = q.front().ss;
        q.pop();
        lvl[curr] = l;
        for(auto x : al[curr]){
            if(!vis[x]){
                vis[x] = true;
                q.push({x, l + 1});
            }
        }
    }
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

    cin >> x >> y >> m;
    al.resize(x + y + 1);
    vis.resize(x + y + 1, false);
    lvl.resize(x + y + 1, 0);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        al[u].pb(v);
        al[v].pb(u);
    }
    int mn1 = INT_MIN, mn2 = INT_MIN;
    bfs(1);
    bfs(x + y);
    for(int i = 1; i <= x; i++) mn1 = max(mn1, lvl[i]);
    for(int i = x + 1; i <= x + y; i++) mn2 = max(mn2, lvl[i]);
    if(mn1 == INT_MAX) mn1 = 0;
    if(mn2 == INT_MAX) mn2 = 0;
    int ans = mn1 + mn2 + 1;
    cout << ans << '\n';
}
