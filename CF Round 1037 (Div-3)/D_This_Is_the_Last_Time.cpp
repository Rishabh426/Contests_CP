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

    vector<vll> arr(n, vll(3, 0));
    f(i, 0, n) {
        ll x; cin >> x;
        ll y; cin >> y;
        ll z; cin >> z;
        arr[i][0] = x, arr[i][1] = y, arr[i][2] = z;
    }

    sort(all(arr), [](vll& A, vll& B) {
        return (A[0] < B[0]);
    });

    ll ans = k;

    f(i, 0, n) {
        if(k >= arr[i][0] && k <= arr[i][1]) {
           k = max(k, arr[i][2]);
        }
    }
    cout << k << nl;
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