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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b)/ (gcd(a, b));
}
void solve() {
    
    int n; 
    cin >> n;

	vll a(n); for(auto &x : a) cin >> x;
	vll b(n); for(auto &x : b) cin >> x;

	bool ans = 1;
	vector<ll> c(n);
	f(i, 0, n) {
		c[i] = lcm(a[i], b[i]);
	}
	int g = c[0];
	f(i, 0, n) {
		g = gcd(g, c[i]);
		if(g != a[i]) ans = false;
	}
    
	g = c[n-1];
	for(int i = n-1; i >= 0; i--) {
		g = gcd(g, c[i]);
		if(g != b[i]) ans = false;
	}

	if(ans) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}