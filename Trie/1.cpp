// Problem link: https://codeforces.com/problemset/problem/706/D
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
    char bit;
    int cnt;
    node *child[2];
    node(char x){
        bit = x;
        cnt = 1;
        for(int i=0; i<2; i++) child[i] = NULL;
    }
};

node *root = new node('\0');

void add(string s){
    node *curr = root;
    for(int i=0; i<s.size(); i++){
        int ind = s[i] - '0';
        if(curr->child[ind] == NULL){
            curr->child[ind] = new node(s[i]);
            curr = curr->child[ind];
        }
        else{
            curr = curr->child[ind];
            curr->cnt++;
        }
    }
}

void sub(string s){
    node *curr = root;
    for(int i=0; i<s.size(); i++){
        int ind = s[i] - '0';
        curr = curr->child[ind];
        curr->cnt--;
    }
}

string ans;

void check(string s){
    node *curr = root;
    for(int i=0; i<s.size(); i++){
        if(s[i] - '0'){
            if(curr->child[0] != NULL && curr->child[0]->cnt){
                ans.pb('0');
                curr = curr->child[0];
            }
            else{
                ans.pb('1');
                curr = curr->child[1];
            }
        }
        else{
            if(curr->child[1] != NULL && curr->child[1]->cnt){
                ans.pb('1');
                curr = curr->child[1];
            }
            else{
                ans.pb('0');
                curr = curr->child[0];
            }
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

    string zero;
    while(zero.size() < 65) zero.pb('0');
    add(zero);
    
    int q; cin>>q;
    while(q--){
        string s; cin>>s;
        if(s == "+"){
            int x; cin>>x;
            string s;
            while(x){
                if(x & 1) s.pb('1');
                else s.pb('0');
                x>>=1;
            }
            reverse(s.begin(), s.end());
            while(s.size() < 65) s = "0" + s;
            add(s);
            
        }
        else if(s == "-"){
            int x; cin>>x;
            string s;
            while(x){
                if(x & 1) s.pb('1');
                else s.pb('0');
                x>>=1;
            }
            reverse(s.begin(), s.end());
            while(s.size() < 65) s = "0" + s;
            sub(s);
        }
        else if(s == "?"){
            int x; cin>>x;
            int temp = x;
            string s;
            while(temp){
                if(temp & 1) s.pb('1');
                else s.pb('0');
                temp>>=1;
            }
            reverse(s.begin(), s.end());
            while(s.size() < 65) s = "0" + s;
            ans.clear();
            check(s);
            ll mx = 0;
            reverse(ans.begin(), ans.end());
            reverse(s.begin(), s.end());
            for(int i=0; i<65; i++){
                if(ans[i] == s[i]) continue;
                else mx += POW(2, i);
            }
            cout<< mx << '\n';
        }
    }
}
