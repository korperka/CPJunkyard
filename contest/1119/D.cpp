#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, c = 0; cin >> n;
        string s;
        bool f = false;
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            if (k == 0) {
                c++;
                s += (f ? 'B' : 'A');
                f = true;
            } else s += 'C';
        }

        if (c == 1) cout << "NO\n";
        else cout << "YES\n" << s << "\n";
    }
}