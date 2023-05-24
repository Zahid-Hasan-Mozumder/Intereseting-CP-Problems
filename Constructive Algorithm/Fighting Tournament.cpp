// Problem link: https://codeforces.com/contest/1719/problem/C
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <sstream>
 
using namespace std;

#define ll long long
#define lli long long int
#define mod 1000000007
#define pi acos(-1.0)
#define PI 3.1415926536


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

    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        vector<int> a(n+1), checkPos(n+1);
        vector<bool> prevBigPresent(n+1, false);
        vector<int> nextBigVal(n+1, 0);
        stack<int> st;
        for(int i=1; i<=n; i++){
            cin>>a[i];
            checkPos[a[i]] = i;
        }
        int currBig = a[1];
        for(int i=2; i<=n; i++){
            if(currBig > a[i]){
                prevBigPresent[i] = true;
            }
            else{
                currBig = a[i];
            }
        }
        for(int i=n; i>=1; i--){
            if(st.empty()){
                nextBigVal[i] = a[i];
            }
            else{
                while(!st.empty() && st.top()<a[i]){
                    st.pop();
                }
                if(st.empty()){
                    nextBigVal[i] = a[i];
                }
                else{
                    nextBigVal[i] = st.top();
                }
            }
            st.push(a[i]);
        }
        while(q--){
            int p, k;
            cin>>p>>k;
            if(a[p] == n){
                if(p == 1)
                    cout<< k << '\n';
                else
                    cout<< max(0, k-(p-2)) << '\n';
            }
            else if(p == 1){
                int win = max(0, checkPos[nextBigVal[p]] - p - 1);
                int ans = min(win, k);
                cout<< ans << '\n';
            }
            else if(p > 1){
                if(prevBigPresent[p]){
                    cout<< 0 << '\n';
                }
                else{
                    int win = max(1, checkPos[nextBigVal[p]] - p);
                    int ans = min(win, max(0, k-(p-2)));
                    cout<< ans << '\n';
                }
            }
        }
    }
}
