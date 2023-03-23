// Problem link: https://cses.fi/problemset/task/1145/
// Here we just using an approach to find the length of LIS by updating the position of smaller elements and inserting bigger elements at right. 
// But the way we are storing the sequence, it will not give us the actual LIS if we try to print it.
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin >> n;
    vector<int> seq;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        auto it = lower_bound(seq.begin(), seq.end(), x);
        if(it == seq.end()){
            seq.pb(x);
        }
        else{
            *it = x;
        }
    }
    cout << seq.size() << '\n';
}
