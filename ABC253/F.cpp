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

template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vi t(q),a(q),b(q),c(q);
    vector<vector<int>> subt(q);
    vector latest(n,pair(-1,0));
    vector<ll> ans;
    forn(i,q){
        cin>>t[i];
        if(t[i] == 1){
            cin>>a[i]>>b[i]>>c[i];
            a[i]--;
        }
        else if(t[i] == 2){
            cin>>a[i]>>b[i];
            a[i] -= 1;
            latest[a[i]] = pair(i,b[i]);
        }
        else{
            cin>>a[i]>>b[i];
            a[i]--;
            const auto& [j,x] = latest[a[i]];
            const int id = ans.size();
            ans.emplace_back(x);
            c[i] = id;
            if(j>=0){
                subt[j].pb(i);
            }
        }
    }
    fenwick<ll> fw(m);
    forn(i,q){
        if(t[i] == 1){
            fw.modify(a[i],c[i]);
            if(b[i]<m) fw.modify(b[i],-c[i]);
        }
        else if(t[i] == 2){
            for(auto j: subt[i]){
                ans[c[j]] -= fw.get(b[j]-1);
            }
        }
        else{
            ans[c[i]] += fw.get(b[i]-1);
        }
    }
    for(auto x: ans){
        cout<<x<<endl;
    }

    return 0;
}