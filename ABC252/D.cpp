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
const ll N = 2e5+10;

ll a[N],s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vi v(n);
    forn(i,n){
        cin>>v[i];
        a[v[i]]++;
    }
    forn(i,N-1) s[i+1] = s[i]+a[i+1];
    ll ans = 0;
    forn(i,n){
        ans += s[v[i]-1] * (n-s[v[i]]);
    }
    cout<<ans<<endl;

    return 0;
}