#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define nl "\n"
#define pi pair<int, int>
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb(a) push_back(a)
#define f(i, start, end) for (int i = start; i < end; ++i)
#define inf 1e9
const int mod = 1e9 + 7;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        f(i,0,n) parent[i] = i;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }
};

void solve() {
    
    ll n, k;
    cin >> n >> k;
    
    vll arr(n);
    for(auto &c : arr) cin >> c;
    
    ll v = arr[k - 1], p = -1;
    sort(all(arr));
    
    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] == v) {
            p = i;
            break;
        }
    }
    
    ll lvl = 0, c = 0;
    f(i, p, n - 1) {
        ll tr = arr[i + 1] - arr[i];
        if(tr + lvl > arr[i]) {
            cout << "NO" << "\n";
            return;
        }
        lvl += tr;
    }
    cout << "YES" << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}