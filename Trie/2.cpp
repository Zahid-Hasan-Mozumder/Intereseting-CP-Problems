// Problem link: https://www.codechef.com/problems/NPLFLF
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

vector<map<int, int, greater<int>>> amount(1e5+5);

struct node{
    char data;
    int cnt;
    node *child[26];
    node(char x){
        data = x;
        cnt = 1;
        for(int i=0; i<26; i++) child[i] = NULL;
    }
};

node *root = new node('\0');

void add(string s){
    node *curr = root;
    int len = 0;
    for(int i=0; i<s.size(); i++){
        int ind = s[i] - 'a';
        if(curr->child[ind]){
            curr = curr->child[ind];
            len++;
            amount[len][curr->cnt]--;
            curr->cnt++;
            amount[len][curr->cnt]++;
        }
        else{
            curr->child[ind] = new node(s[i]);
            curr = curr->child[ind];
            len++;
            amount[len][curr->cnt]++;
        }
    }
}

void remove(string s){
    node *curr = root;
    int len = 0;
    for(int i=0; i<s.size(); i++){
        int ind = s[i] - 'a';
        curr = curr->child[ind];
        len++;
        amount[len][curr->cnt]--;
        curr->cnt--;
        amount[len][curr->cnt]++;
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

    int op; cin>>op;
    vector<bool> done(op+1, false);
    vector<string> ss(op+1);
    for(int i=1; i<=op; i++){
        int qt; cin>>qt;
        if(qt == 1){
            string s; cin>>s;
            reverse(s.begin(), s.end());
            ss[i] = s;
            add(s);
        }
        else if(qt == 2){
            int k, l; cin>>k>>l;
            int mx = -1;
            for(auto it : amount[l]){
                if(it.second >= 1){
                    mx = it.first;
                    break;
                }
            }
            if(mx >= k) cout<< "YES" << '\n';
            else cout<< "NO" << '\n';
        }
        else if(qt == 3){
            int x; cin>>x;
            if(!done[x]){
                remove(ss[x]);
                done[x] = true;
            }
        }
    }
}
