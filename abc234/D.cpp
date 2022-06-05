#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<int>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int N = 1e5+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vi a(n);
    forn(i,n) cin>>a[i];
    priority_queue<int,vector<int>,greater<int>> q1;
    priority_queue<int> q2;
    sort(a.begin(),a.begin()+k,greater<int>());
    forn(i,k-1) q1.push(a[i]);
    q2.push(a[k-1]);
    cout<<a[k-1]<<endl;
    fore(i,k,n-1){
        if(a[i]>q2.top()){
            q1.push(a[i]);
            q2.push(q1.top());
            q1.pop();
        }
        else{
            q2.push(a[i]);
        }
        cout<<q2.top()<<endl;
    }

    return 0;
}