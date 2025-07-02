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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int f1 = count(all(s), '1');

    if(f1 <= k || n / k <= 1) cout << "Alice" << nl;
    else cout << "Bob" << nl;  

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