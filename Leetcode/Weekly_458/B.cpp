#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, size;
    int components;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        components = n;
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    bool unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return false;

        if (size[xr] < size[yr]) {
            parent[xr] = yr;
            size[yr] += size[xr];
        } else {
            parent[yr] = xr;
            size[xr] += size[yr];
        }
        components--;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int countComponents() {
        return components;
    }
};
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        
        // APPROACH :-
        /*
            we would consider that the graph initially has n components 
            and we will add edges based on the edge weights i.e we will be 
            adding lower edge weight first, for this we sort the edges by weight
            in ascending order. And then we gradually start adding the edges
            when the connected components becomes equal to k, we return our ans.
        */
        sort(edges.begin(), edges.end(), [](vector<int>& A, vector<int>& B) {
            return (A[2] < B[2]);
        });

        int ans = 0;
        DSU d(n);

        for(auto &e : edges) {
            if(d.countComponents() == k) break;
            if(d.unite(e[0], e[1])) {
                ans = max(ans, e[2]);
            }
        }
        return ans;
    }
};