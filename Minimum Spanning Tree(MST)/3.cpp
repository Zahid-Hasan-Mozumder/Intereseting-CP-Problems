// Problem link: https://www.codechef.com/problems/ICL16A
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define plpii pair<ll, pair<int, int>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

int ans = INT_MIN;

void prims(vvpii &al){
    int n = al.size();
    vb vis(n, false);
    priority_queue<pipii, vpipii, greater<pipii>> pq;
    pq.push({0, {0, -1}});
    while(!pq.empty()){
        auto it = pq.top();
        int dist = it.ff;
        int u = it.ss.ff;
        int v = it.ss.ss;
        pq.pop();
        if(!vis[u]){
            vis[u] = true;
            ans = max(ans, dist);
            for(auto adj : al[u]){
                if(!vis[adj.ff]) 
                    pq.push({adj.ss, {adj.ff, u}});
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

    int n, m; cin>>n>>m;
    vs grid;
    vvpii al(n);
    for(int i=0; i<n; i++){
        string s; cin>>s;
        grid.pb(s);
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int dist = INT_MIN;
            for(int k=0; k<m; k++){
                dist = max(dist, abs(grid[i][k] - grid[j][k]));
            }
            al[i].pb({j, dist});
            al[j].pb({i, dist});
        }
    }
    prims(al);
    cout<< ans << '\n';
}
