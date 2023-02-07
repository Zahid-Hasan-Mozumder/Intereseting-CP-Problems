// Problem link: https://www.spoj.com/problems/SUBXOR/en/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
const int maxN = 1e6;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

string toString(ll x){
    string s;
    while(x){
        if(x & 1) s.pb('1');
        else s.pb('0');
        x>>=1;
    }
    reverse(s.begin(), s.end());
    while(s.size() < 21) s = "0" + s;
    return s;
}

struct node{
    char data;
    int cnt;
    node *child[2];
    node(char x){
        data = x;
        cnt = 1;
        for(int i=0; i<2; i++) child[i] = NULL;
    }
};

void add(node *curr, string s){
    for(int i=0; i<s.size(); i++){
        int ind = s[i] - '0';
        if(curr->child[ind] != NULL){
            curr = curr->child[ind];
            curr->cnt++;
        }
        else{
            curr->child[ind] = new node(s[i]);
            curr = curr->child[ind];
        }
    }
}

void check(node *curr, string s, string k, ll &ans){
    for(int i=0; i<k.size(); i++){
        int x = k[i] - '0', y = s[i] - '0';
        if(x){
            if(curr->child[y]) ans += (ll)curr->child[y]->cnt;
            if(curr->child[y ^ 1]) curr = curr->child[y ^ 1];
            else return;
        }
        else{
            if(curr->child[y]) curr = curr->child[y];
            else return;
        }
    }
}

void del(node *curr){
    for(int i=0; i<2; i++){
        if(curr->child[i] != NULL){
            del(curr->child[i]);
        }
    }
    delete(curr);
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

    int t; cin>>t;
    while(t--){
        ll n, k; cin>>n>>k;
        vll a(n+1, 0), pre(n+1, 0);
        for(int i=1; i<=n; i++){
            cin>>a[i];
            pre[i] = pre[i - 1] ^ a[i];
        }
        string K = toString(k);
        ll ans = 0;
        node *root = new node('\0');
        add(root, toString(pre[n]));
        for(int i=n-1; i>=0; i--){
            string s = toString(pre[i]);
            check(root, s, K, ans);
            add(root, s);
        }
        cout<< ans << '\n';
        del(root);
    }
}
