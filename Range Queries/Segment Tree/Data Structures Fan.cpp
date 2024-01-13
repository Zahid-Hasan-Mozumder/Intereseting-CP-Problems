// Problem link: https://codeforces.com/contest/1872/problem/E
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

const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

vi a, txor, zxor, lazy;
string s;

void init(int n){
    a.clear(); txor.clear(); zxor.clear(); lazy.clear();
    a.resize(n, 0); txor.resize(4 * n, 0); zxor.resize(4 * n, 0); lazy.resize(4 * n, 0);
    s.clear();
}

void build(int ind, int l, int r){
    if(l == r){
        txor[ind] = a[l];
        if(s[l] == '0') zxor[ind] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * ind + 1, l, mid);
    build(2 * ind + 2, mid + 1, r);
    txor[ind] = txor[2 * ind + 1] ^ txor[2 * ind + 2];
    zxor[ind] = zxor[2 * ind + 1] ^ zxor[2 * ind + 2];
}

void update(int ind, int st, int en, int l, int r){
    if(lazy[ind]){
        if(lazy[ind] & 1) zxor[ind] = txor[ind] ^ zxor[ind];
        if(st != en){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        zxor[ind] = txor[ind] ^ zxor[ind];
        if(st != en){
            lazy[2 * ind + 1]++;
            lazy[2 * ind + 2]++;
        }
        return;
    }
    int mid = (st + en) / 2;
    update(2 * ind + 1, st, mid, l, r);
    update(2 * ind + 2, mid + 1, en, l, r);
    zxor[ind] = zxor[2 * ind + 1] ^ zxor[2 * ind + 2];
}

void query(int ind, int st, int en){
    if(lazy[ind]){
        if(lazy[ind] & 1) zxor[ind] = txor[ind] ^ zxor[ind];
        if(st != en){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    return;
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
        init(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        cin >> s;
        build(0, 0, n - 1);
        int q; cin >> q;
        while(q--){
            int qt; cin >> qt;
            if(qt == 1){
                int l, r; 
                cin >> l >> r;
                l--; r--;
                update(0, 0, n - 1, l, r);
            }
            else if(qt == 2){
                int g; cin >> g;
                query(0, 0, n - 1);
                int ans = 0;
                if(g) ans = (txor[0] ^ zxor[0]);
                else ans = zxor[0];
                cout << ans << " ";
            }
        }
        cout << '\n';
    }
}
