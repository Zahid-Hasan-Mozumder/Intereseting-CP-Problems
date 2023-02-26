// Problem link: https://lightoj.com/problem/making-huge-palindromes
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

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

vector<int> create_lps(string s){
    vector<int> lps(s.size(), 0);
    int ind = 0;
    for(int i=1; i<s.size(); ){
        if(s[ind] == s[i]){
            lps[i] = ind + 1;
            ind++; i++;
        }
        else{
            if(ind != 0) ind = lps[ind - 1];
            else i++;
        }
    }
    return lps;
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

    int cs = 1;
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        string x = s;
        reverse(x.begin(), x.end());
        x = x + "#" + s;
        vector<int> lps = create_lps(x);
        int matched = lps[lps.size() - 1];
        cout<< "Case " << cs << ": " << s.size() + (s.size() - matched) << '\n';
        cs++;
    }
}
