#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define sz(a) ll((a).size())
#define endl "\n"
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<ll>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
const ll N = 30+10;

ll n;
ll a[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    forn(i,n){
        forn(j,i+1){
            if(j==0 || j==i) a[i][j] = 1;
            else a[i][j] = a[i-1][j-1]+a[i-1][j];
            cout<<a[i][j]<<" \n"[j==i];
        }
    }

    return 0;
}