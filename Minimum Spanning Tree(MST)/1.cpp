// Problem link: https://lightoj.com/problem/civil-and-evil-engineer
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

#define vb vector<bool>
#define plpii pair<ll, pair<int, int>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

ll minST(vvpil &al){
    int n = al.size();
    ll sum = 0;
    priority_queue<plpii, vplpii, greater<plpii>> pq;
    vb vis(n, false);
    pq.push({0, {0, -1}});
    while(!pq.empty()){
        auto it = pq.top();
        ll w = it.ff;
        int child = it.ss.ff, parent = it.ss.ss;
        pq.pop();
        if(!vis[child]){
            vis[child] = true;
            sum += w;
            for(auto adj : al[child]){
                if(!vis[adj.ff]){
                    pq.push({adj.ss, {adj.ff, child}});
                }
            }
        }
    }
    return sum;
}

ll maxST(vvpil &al){
    int n = al.size();
    ll sum = 0;
    priority_queue<plpii> pq;
    vb vis(n, false);
    pq.push({0, {0, -1}});
    while(!pq.empty()){
        auto it = pq.top();
        ll w = it.ff;
        int child = it.ss.ff, parent = it.ss.ss;
        pq.pop();
        if(!vis[child]){
            vis[child] = true;
            sum += w;
            for(auto adj : al[child]){
                if(!vis[adj.ff]){
                    pq.push({adj.ss, {adj.ff, child}});
                }
            }
        }
    }
    return sum;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    
    zahid();
    
    int cs = 1;
    int t; cin>>t;
    while(t--){
        string line; getline(cin, line);
        int n; cin>>n;
        vvpil al(n+1);
        ll u, v, w;
        while(cin>>u>>v>>w){
            if(u == 0 && v == 0 && w == 0) break;
            al[u].pb({v, w});
            al[v].pb({u, w});
        }
        ll mn = minST(al);
        ll mx = maxST(al);
        cout<< "Case " << cs << ": ";
        if((mx + mn) & 1)
             cout<< (mx + mn) << "/" << 2 << '\n';
        else
            cout<< (mx + mn) / 2LL << '\n';
        cs++;
    }
}
