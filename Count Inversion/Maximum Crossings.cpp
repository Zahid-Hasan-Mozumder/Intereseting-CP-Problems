// Problem link: https://codeforces.com/problemset/problem/1676/H2
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

vi cnt;

void merge(vi &a, int s, int m, int e){
    vi l, r;
    for(int i = s; i <= m; i++) l.pb(a[i]);
    for(int i = m + 1; i <= e; i++) r.pb(a[i]);
    int i = 0, j = 0, k = s;
    while(i < l.size() && j < r.size()){
        if(l[i] >= r[j]){
            a[k] = r[j];
            cnt[m + 1 + j] += (l.size() - i);
            j++;
            k++;
        }
        else{
            a[k] = l[i];
            i++;
            k++;
        }
    }
    while(i < l.size()){
        a[k] = l[i];
        i++;
        k++;
    }
    while(j < r.size()){
        a[k] = r[j];
        j++;
        k++;
    }
}

void countInversion(vi &a, int s, int e){
    if(s < e){
        int mid = (s + e) / 2;
        countInversion(a, s, mid);
        countInversion(a, mid + 1, e);
        merge(a, s, mid, e);
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

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cnt.clear();
        cnt.resize(n, 0);
        ll ans = 0;
        countInversion(a, 0, n - 1);
        ans = accumulate(cnt.begin(), cnt.end(), 0ll);
        cout << ans << '\n';
    }
}
