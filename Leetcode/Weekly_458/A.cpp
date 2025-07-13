#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        
        int n = s.length();
        string ans = "";

        for(int i = 0; i < n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                ans.push_back(s[i]);
            }
            else if(s[i] == '*') {
                if(ans.empty()) continue;
                ans.pop_back();
            }
            else if(s[i] == '#') ans += ans;
            else if(s[i] == '%') reverse(begin(ans), end(ans));
        }

        return ans;
    }
};