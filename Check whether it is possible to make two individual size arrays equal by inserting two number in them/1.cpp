// Problem link: https://codeforces.com/contest/1776/problem/L
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

ll GCD(ll a, ll b){
    ll temp;
    while(b){
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

ll LCM(ll a, ll b){
    return (a/GCD(a,b))*b;
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
    string s; cin>>s;
    ll pos = 0, neg = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '+') pos++;
        else neg++;
    }
    int q; cin>>q;
    while(q--){
        ll a, b; cin>>a>>b;
        if(pos == neg){
            cout<< "YES" << '\n';
        }
        else{
            if(a == b){
                cout<< "NO" << '\n';
            }
            else{
                ll l = LCM(a, b);
                ll x = l / a;
                ll y = l / b;
                ll c = abs(pos - neg) / abs(x - y);
                if(abs(pos - neg) % abs(x - y) == 0){
                    if(c * min(x, y) <= min(pos, neg) && c * max(x, y) <= max(pos, neg)){
                        cout<< "YES" << '\n';
                    }
                    else{
                        cout<< "NO" << '\n';
                    }
                }
                else{
                    cout<< "NO" << '\n';
                }
            }      
        }
    }
}
