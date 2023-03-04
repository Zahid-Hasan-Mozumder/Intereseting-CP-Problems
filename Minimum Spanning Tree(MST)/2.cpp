// Problem link: https://www.spoj.com/problems/MARYBMW/en/
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define pipii pair<int, pair<int, int>, int>
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
#define si stack<int>
#define sll stack<ll>
#define qi queue<int>
#define qll queue<ll>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;


ll maxST(vvpil &al){
    int n = al.size();
    ll mxSpeed = LLONG_MAX;
    priority_queue<plpii> pq;
    vb vis(n, false);
    pq.push({LLONG_MAX, {1, -1}});
    while(!pq.empty()){
        auto it = pq.top();
        ll currSpeed = it.ff;
        int child = it.ss.ff, parent = it.ss.ss;
        pq.pop();
        if(!vis[child]){
            vis[child] = true;
            mxSpeed = min(mxSpeed, currSpeed);
            if(child == n-1) return mxSpeed;
            for(auto adj : al[child]){
                if(!vis[adj.ff]){
                    pq.push({adj.ss, {adj.ff, child}});
                }
            }
        }
    }
    return -1;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vvpil al(n+1);
        for(int i=0; i<m; i++){
            ll u, v, w;
            cin>>u>>v>>w;
            al[u].pb({v, w});
            al[v].pb({u, w});
        }
        ll mn = maxST(al);
        cout<< mn << '\n';
    }
}
