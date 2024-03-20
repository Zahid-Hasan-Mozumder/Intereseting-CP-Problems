// Problem link: https://codeforces.com/problemset/problem/1900/D
// Explanation Video: https://www.youtube.com/watch?v=5bVAZgy1u5E&t=2401s
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define vvvi vector<vector<vector<int>>>
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

//const ll mod = 1e9 + 7;
const ll mod = 998244353;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

vvll d;

void generate(){
    d.clear(); d.resize(1e5 + 1);
    for(ll i = 1; i <= 1e5; i++){
        for(ll j = 1; j * j <= i; j++){
            if(i % j == 0){
                d[i].pb(j);
                if(i / j != j) d[i].pb(i / j);
            }
        }
        sort(d[i].rbegin(), d[i].rend());
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
    generate();

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vll a(n);
        for(int i = 0; i < n; i++) 
            cin >> a[i];
        sort(a.begin(), a.end());
        unordered_map<ll, ll> cnt;
        ll ans = 0, rem = n;
        for(int i = 0; i < n; i++){
            rem--;
            unordered_map<ll, ll> tmp;
            for(auto x : d[a[i]]){
                ll c = cnt[x] - tmp[x];
                if(c > 0){
                    ans += x * c * rem;
                    for(auto xx : d[x]){
                        tmp[xx] += c;
                    }
                }
            }
            for(auto x : d[a[i]])
                cnt[x]++;   
        }
        cout << ans << '\n';
    }
}
