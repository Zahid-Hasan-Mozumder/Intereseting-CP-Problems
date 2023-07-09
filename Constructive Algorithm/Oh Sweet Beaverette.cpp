// Problem link: https://codeforces.com/problemset/problem/331/A2
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

void zahid(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin >> n;
    vll a(n + 1), pre(n + 1, 0);
    map<ll, pair<int, int>> mp;
    map<ll, ll> cnt;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(mp[a[i]].ff == 0){
            mp[a[i]].ff = i;
            mp[a[i]].ss = i;
        }
        else{
            mp[a[i]].ss = i;
        }
        cnt[a[i]]++;
        // Ignoring negative values because they are going to reduce the main sum
        if(a[i] >= 0) pre[i] = a[i];
        pre[i] += pre[i - 1];
    }
    int l = -1, r = -1;
    ll mx = INT_MIN;
    for(auto it : mp){
        // ....X............X.....
        if(cnt[it.ff] >= 2){
            // ...5...........5.....
            if(it.ff >= 0 && pre[it.ss.ss] - pre[it.ss.ff - 1] > mx){
                mx = pre[it.ss.ss] - pre[it.ss.ff - 1];
                l = it.ss.ff, r = it.ss.ss;
            }
            // ...-2..........-2....
            else if(it.ff < 0 && pre[it.ss.ss] - pre[it.ss.ff - 1] + (2 * (it.ff)) > mx){
                mx = pre[it.ss.ss] - pre[it.ss.ff - 1] + (2 * (it.ff));
                l = it.ss.ff, r = it.ss.ss;
            }
        }
    }
    ll k = 0;
    vll ind;
    for(int i = 1; i < l; i++){
        k++;
        ind.pb(i);
    }
    for(int i = l + 1; i < r; i++){
        if(a[i] < 0){
            k++;
            ind.pb(i);
        }
    }
    for(int i = r + 1; i <= n; i++){
        k++;
        ind.pb(i);
    }
    cout << mx << " " << k << '\n';
    for(auto x : ind) cout << x << " ";
    cout << '\n';
}
