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
    int n;
    cin>>n;
    vector<vector<int>> a(10,vector<int>(10));
    forn(i,n){
        string s;
        cin>>s;
        forn(j,10){
            a[s[j]-'0'][j]++;
        }
    }
    int ans = 1e9;
    forn(i,10){
        int x = 0;
        int p = 0;
        forn(j,10){
            if(a[i][j]>=x){
                x = a[i][j];
                p = j;
            }
        }
        ans = min(ans,(x-1)*10+p);
    }
    cout<<ans<<endl;

    return 0;
}