// Problem link: https://codeforces.com/problemset/problem/1658/D2
// Video editorial: https://www.youtube.com/watch?v=8OfQHb8en5I
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

struct node{
    int bit;
    node *child[2];
    node(int x){
        bit = x;
        for(int i = 0; i < 2; i++) child[i] = NULL;
    }
};

void add(node *root, vi a){
    node *curr = root;
    for(int i = 0; i < a.size(); i++){
        if(curr->child[a[i]] != NULL){
            curr = curr->child[a[i]];
        }
        else{
            curr->child[a[i]] = new node(a[i]);
            curr = curr->child[a[i]];
        }
    }
}

void min_search(node *root, vi x, int &mn){
    node *curr = root;
    int j = 17;
    for(int i = 0; i < x.size(); i++){
        if(curr->child[x[i]] != NULL){
            curr = curr->child[x[i]];
            j--;
        }
        else{
            mn ^= (1 << j);
            curr = curr->child[x[i] ^ 1];
            j--;
        }
    }
}

void max_search(node *root, vi x, int &mx){
    node *curr = root;
    int j = 17;
    for(int i = 0; i < x.size(); i++){
        if(curr->child[x[i] ^ 1] != NULL){
            mx ^= (1 << j);
            curr = curr->child[x[i] ^ 1];
            j--;
        }
        else{
            curr = curr->child[x[i]];
            j--;
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

    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        int n = r - l + 1;
        vi a(n), x(n);
        vvi aa(n, vi(18, 0)), xx(n, vi(18, 0));
        for(int i = 0; i < n; i++){
            cin >> a[i];
            int j = 0, tmp = a[i];
            while(tmp){
                if(tmp & 1) aa[i][j] = 1;
                tmp >>= 1;
                j++;
            }
            x[i] = a[i] ^ l;
            j = 0, tmp = x[i];
            while(tmp){
                if(tmp & 1) xx[i][j] = 1;
                tmp >>= 1;
                j++;
            }
        }
        node *root = new node(0);
        for(int i = 0; i < n; i++){
            reverse(aa[i].begin(), aa[i].end());
            add(root, aa[i]);
        }
        int ans = -1;
        for(int i = 0; i < n; i++){
            int mn = 0, mx = 0;
            reverse(xx[i].begin(), xx[i].end());
            min_search(root, xx[i], mn);
            max_search(root, xx[i], mx);
            if(mn == l && mx == r){
                ans = x[i];
                break;
            }
        }
        cout << ans << '\n';
    }
}
