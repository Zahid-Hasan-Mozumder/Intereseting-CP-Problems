// Problem link : https://lightoj.com/problem/funny-knapsack
// Tutorial : https://ojsolver.blogspot.com/2021/05/lightoj-1127-funny-knapsack-tutorial.html?spref=fb
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <sstream>
#include <string>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
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
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vvpli vector<vector<pair<ll, int>>>
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

ll POW(ll a, ll b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll x = POW(a, b/2);
    if(b&1) return (x * x * a);
    else return (x * x);
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
        ll n, w; cin>>n>>w;
        vll a, b, com1, com2;
        for(int i=1; i<=n; i++){
            ll x; cin>>x;
            if(i <= n/2) a.pb(x);
            else b.pb(x);
        }
        ll x = POW(2, n/2), y = POW(2, n - (n / 2));
        for(int i = 0; i < x; i++){
            int temp = i;
            ll curr = 0;
            int pos = 0;
            while(temp){
                if(temp & 1) curr += a[pos];
                temp>>=1;
                pos++;
            }
            com1.pb(curr);
        }
        for(int i = 0; i < y; i++){
            int temp = i;
            ll curr = 0;
            int pos = 0;
            while(temp){
                if(temp & 1) curr += b[pos];
                temp>>=1;
                pos++;
            }
            com2.pb(curr);
        }
        sort(com1.begin(), com1.end());
        sort(com2.begin(), com2.end());
        ll ans = 0;
        for(int i=0; i<com1.size(); i++){
            ll extra = w - com1[i];
            ll ub = upper_bound(com2.begin(), com2.end(), extra) - com2.begin();
            ans += ub;
        }
        cout<< "Case " << cs << ": " << ans << '\n';
        cs++;
    }
}
