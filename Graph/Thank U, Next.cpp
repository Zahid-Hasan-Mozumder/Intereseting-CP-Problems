// Problem link: https://www.codechef.com/problems/MAIL_DELIVER?tab=statement
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

bool bfs(vvi &al, vi &x, vi &d, int n, int k){
    vb vis(n + 1, false);
    priority_queue<pii> pq;
    for(int i = 1; i <= k; i++) pq.push({d[i] - 1, x[i]});
    while(!pq.empty()){
        int rem = pq.top().ff;
        int curr = pq.top().ss;
        pq.pop();
        vis[curr] = true;
        if(rem == 0) continue;
        for(auto v : al[curr]){
            if(!vis[v]){
                vis[v] = true;
                pq.push({rem - 1, v});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) return false;
    }
    return true;
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
        int n, m, k; cin >> n >> m >> k;
        vi x(k + 1), d(k + 1);
        for(int i = 1; i <= k; i++) cin >> x[i];
        for(int i = 1; i <= k; i++) cin >> d[i];
        vvi al(n + 1);
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            al[u].pb(v);
            al[v].pb(u);
        }
        if(bfs(al, x, d, n, k)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
