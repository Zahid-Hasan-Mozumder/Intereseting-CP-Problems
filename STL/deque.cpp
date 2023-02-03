//Problem link: https://toph.co/p/stacklang
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <sstream>
#include <string>

using namespace std;

#define ll long long int

const ll mod = 1e9+7;
const int maxN = 1e6;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;


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

    ll sum = 0;
    deque<int> dq;
    string s;
    int rev = 0;
    while(cin>>s){
        if(s == "PUSH"){
            int x; cin>>x;
            if(rev){
                if(dq.size() >= maxN){
                    sum -= dq.back();
                    dq.pop_back();
                }
                dq.push_front(x);
            }
            else{
                if(dq.size() >= maxN){
                    sum -= dq.front();
                    dq.pop_front();
                }
                dq.push_back(x);
            }
            sum += x;
        }
        else if(s == "POP"){
            if(!dq.empty()){
                if(rev){
                    sum -= dq.front(); 
                    dq.pop_front();
                }
                else{
                    sum -= dq.back(); 
                    dq.pop_back();
                }
            }
        }
        else if(s == "PRINT"){
            if(dq.empty()) cout<< "-" << '\n';
            else cout<< (rev ? dq.front() : dq.back()) << '\n';
        }
        else if(s == "SIZE"){
            if(dq.empty()) cout<< "0" << '\n';
            else cout<< dq.size() << '\n';
        }
        else if(s == "SUM"){
            cout<< sum << '\n';
        }
        else if(s == "REPEAT"){
            int x; cin>>x;
            if(x > 0 && dq.size() < maxN){
                int sz = dq.size();
                int need = maxN - dq.size();
                while(dq.size() < maxN && x--){
                    int i = 0;
                    while(i < sz && dq.size() < maxN){
                        if(rev){
                            dq.push_back(dq[i]);
                            sum += dq.back();
                        }
                        else{
                            dq.push_front(dq[dq.size() - 1 - i]);
                            sum += dq.front();
                        }
                        i++;
                    }
                }
            }
        }
        else if(s == "REVERSE"){
            rev ^= 1;
        }
    }
}
