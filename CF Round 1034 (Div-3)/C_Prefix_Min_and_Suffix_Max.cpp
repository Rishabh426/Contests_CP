#include <bits/stdc++.h>
using namespace std;
 
//////////////////////////// basic template /////////////////////////////////////////////////////////////
 
// template<typename A, typename B>
// ostream& operator<<(ostream &os, const pair<A, B> &p) {
//     return os << '(' << p.first << ", " << p.second << ')';
// }
 
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
// ostream& operator<<(ostream &os, const T_container &v) {
//     os << '{';
//     string sep;
//     for (const T &x : v)
//         os << sep << x, sep = ", ";
//     return os << '}';
// }
 
//////////////////////////// basic macros ///////////////////////////////////////////////////////////////
 
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define nl "\n" 
#define pi pair<int, int>
#define pl pair<long long, long long>
#define sz(x) ((int)x.size())         // sz(vector) will give vector size
#define all(a) (a).begin(), (a).end() // for sorting use sort(all(myVector));
#define floop(i, start, end) for (int i = start; i < end; ++i)
#define fnloop(i, start, end) for (int i = start; i >= end; --i)

void solve()
{
    int n;
    cin >> n;

    vi arr(n), pref(n), suff(n);
    for(auto &c : arr) cin >> c;

    unordered_map<int, bool> mpp;
    mpp[0] = 1;
    mpp[n - 1] = 1;

    pref[0] = arr[0];
    floop(i, 1, n) {
        if(pref[i - 1] >= arr[i]) {
            pref[i] = arr[i];
            mpp[i] = 1;
        }
        else pref[i] = pref[i - 1];
    }

    suff[n - 1] = arr[n - 1];
    fnloop(i, n - 2, 0) {
        if(suff[i + 1] <= arr[i]) {
            suff[i] = arr[i];
            mpp[i] = 1;
        }
        else suff[i] = suff[i + 1];
    }

    floop(i, 0, n) {
        if(mpp[i]) cout << "1";
        else cout << "0";
    }
    
    cout << nl;
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}