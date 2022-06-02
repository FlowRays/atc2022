#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define sz(a) ll((a).size())
#define endl "\n"
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<ll>
#define debug cout<<"test"<<endl

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
const ll N = 1e5+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,l,r;
    cin>>n>>l>>r;
    l--;
    vi a(n);
    iota(all(a),1);
    ll x = 0;
    ll cnt = 0;
    
    while(cnt + (n-x-1) <= l){
        cnt += n-x-1;
        x++;
    }
    ll y = x+1;
    
    while(cnt<l){
        cnt++;
        y++;
    }
    while(cnt<r && y<n){
        swap(a[x],a[y]);
        cnt++;
        y++;
    }
    x++;
    ll t = x;
    
    while(cnt+(n-x-1)<r){
        cnt += n-x-1;
        x++;
    }
    
    reverse(a.begin()+t,a.end());
    reverse(a.begin()+x,a.end());
    y = x+1;
    while(cnt<r && y<n){
        swap(a[x],a[y]);
        cnt++;
        y++;
    }
    forn(i,n) cout<<a[i]<<" \n"[i==n-1];

    return 0;
}