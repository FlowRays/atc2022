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

int solve(int x){
    unordered_map<int,int> primes;
    for(int i=2;i<=x/i;++i){
        while(x%i == 0){
            x/=i;
            primes[i]++;
        }
    }
    if(x>1) primes[x]++;
    int res = 1;
    for(auto p: primes) res *= p.second+1;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int ans = 0;
    fore(i,1,n){
        ans += solve(i);
    }
    cout<<ans<<endl;

    return 0;
}