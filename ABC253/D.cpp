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
const ll N = 1e5+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull n,a,b;
    cin>>n>>a>>b;
    // 容斥原理 lcm
    ull k = a*b/gcd(a,b); 
    ull t = (a+n/a*a)*(n/a)/2 + (b+n/b*b)*(n/b)/2 - (k+n/k*k)*(n/k)/2;
    cout<<(1+n)*n/2-t<<endl;
    return 0;
}