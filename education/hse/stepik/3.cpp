#include<bits/stdc++.h>

using ll = long long;
using namespace std;

void dfs(int v, vector<vector<ll>>& g, vector<int>& col, bool& hasCycle) {
    col[v] = 1;

    for (int i = 0; i < g.size(); i++) {
        if (g[v][i] == 1) {
            if (col[i] == 0) {
                dfs(i, g, col, hasCycle);
                if(hasCycle) return;
            }
            else if (col[i] == 1) {
                hasCycle = true;
                return;
            }
        }
    }

    col[v] = 2;
}

int main() {
    ll n; cin >> n;
    vector g(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    bool hasCycle = false;
    vector<int> col(g.size(), 0);
    dfs(0, g, col, hasCycle);

    cout << hasCycle << "\n";
}