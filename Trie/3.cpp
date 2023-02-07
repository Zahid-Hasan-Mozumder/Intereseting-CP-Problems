// Problem link: https://codeforces.com/problemset/problem/282/E
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
        --------------------------------------------------------------
        ||||||||||||                    ||||||||||||||||||||||||||||||           ==> Xor between these selected segments of array elements
        --------------------------------------------------------------
*/
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
    while(s.size() < 40) s = "0" + s;
    return s;
}

ll POW(ll a, ll b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll x = POW(a, b/2);
    if(b&1) return (x * x * a);
    else return (x * x);
}

struct node{
    char data;
    node *child[2];
    node(char x){
        data = x;
        for(int i=0; i<2; i++) child[i] = NULL;
    }
};

node *root = new node('\0');

void add(string s){
    node *curr = root;
    for(int i=0; i<s.size(); i++){
        int ind = s[i] - '0';
        if(curr->child[ind] != NULL) curr = curr->child[ind];
        else{
            curr->child[ind] = new node(s[i]);
            curr = curr->child[ind];
        }
    }
}

ll check(string s){
    node *curr = root;
    ll ans = 0;
    for(int i=0; i<s.size(); i++){
        int ind = s[i] - '0';
        if(curr->child[ind ^ 1] != NULL){
            ans += POW(2, 39 - i);
            curr = curr->child[ind ^ 1];
        }
        else{
            curr = curr->child[ind];
        }
    }
    return ans;
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

    int n; cin>>n;
    vll a(n), pre(n+2, 0), suf(n+2, 0);
    for(int i=0; i<n; i++){
        cin>>a[i];
        pre[i+1] = pre[i] ^ a[i];
    }
    for(int i=n-1; i>=0; i--) suf[i+1] = suf[i+2] ^ a[i];
    ll ans = LLONG_MIN;
    for(int i=0; i<=n; i++){
        string p = toString(pre[i]);
        string s = toString(suf[i+1]);
        add(p);
        ans = max(ans, check(s));
    }
    cout<< ans << '\n';
}
