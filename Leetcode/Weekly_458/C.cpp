#include <bits/stdc++.h>
using namespace std;

class Solution {
    #define ll long long
public:
    char processStr(string s, ll k) {
        
        // APPROACH :-
        /*
            First we will calculate the length of the string after performing
            all the operations, then if after performing all the operations
            n <= k then we can simply return '.' as we do not have any value at
            kth index, otherwise we could now start undoing the operations from 
            last and suppose we have a reverse operation in that case k will 
            become n - k - 1, and for copy operation if k >= n / 2 then k would 
            reduce by n / 2 otherwise it would remain same.
        */
        ll n = 0;
        for(auto &x : s) {
            if(x == '*') n = max(0LL, n - 1);
            else if(x == '%') continue;
            else if(x == '#') n *= 2;
            else n++;
        }

        if(n <= k) return '.';

        reverse(s.begin(), s.end());

        for(auto &x : s) {
            if(x == '*') ++n;
            else if(x == '%') k = n - k - 1;
            else if(x == '#') {
                n /= 2;
                if(k >= n) k -= n;
            }
            else {
                --n;
                if(n <= k) return x;
            }
        }
        return '.';
    }
};