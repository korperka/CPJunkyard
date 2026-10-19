#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> g(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) g[0][i] = !a[0][i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j] = g[i-1][j] + !a[i][j];

            if (a[i][j]) g[i][j] = 0;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> st;
        vector<int> l(m), r(m);
        for (int j = 0; j < m; j++) {
            while (!st.empty() && g[i][st.back()] >= g[i][j]) st.pop_back();
            l[j] = (st.empty() ? -1 : st.back());
            st.push_back(j);
        }
        st.clear();
        for (int j = m-1; j >= 0; j--) {
            while (!st.empty() && g[i][st.back()] >= g[i][j]) st.pop_back();
            r[j] = (st.empty() ? m : st.back());
            st.push_back(j);
        }

        for (int j = 0; j < m; j++) {
            ll w = r[j] - l[j] - 1;
            ans = max(ans, w*g[i][j]);
        }
    }

    cout << ans << "\n";
}
