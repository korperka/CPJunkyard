#include<bits/stdc++.h>

using ll = long long;
using namespace std;

bool check(int v, vector<vector<ll>>& g, vector<int>& col) {
    col[v] = 1;

    for (int i = 0; i < g.size(); i++) {
        if (g[v][i] == 1) {
            if (col[i] == 0) return check(i, g, col);
            else if (col[i] == 1) return true;
        }
    }

    col[v] = 2;

    return false;
}

int main() {
    ll n; cin >> n;
    vector g(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];


}