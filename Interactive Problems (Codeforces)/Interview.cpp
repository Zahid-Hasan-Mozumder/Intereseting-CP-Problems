// Problem link: https://codeforces.com/contest/1807/problem/E
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

void ask(int l, int r){
    ll k = r - l + 1;
    cout << "? " << k;
    for(int i = l; i <= r; i++){
        cout<< " " << i;
    }
    cout<< '\n';
    cout.flush();
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin>>t;
    while(t--){
        int n; cin >> n;
        vll a(n + 1), pre(n + 1, 0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            pre[i] = a[i] + pre[i - 1];
        }
        ll low = 1, high = n;
        while(low < high){
            ll mid = (low + high) / 2;
            ll need = pre[mid] - pre[low - 1];
            ask(low, mid);
            ll given; cin>>given;
            if(given > need){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        cout<< "! " << low << '\n';
        cout.flush();
    }
}
