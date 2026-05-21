#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int ans = 0;
        string s; cin >> s;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 1; i+j <= s.length(); j++) {
                string p = s.substr(i, j);

                if (p == s.substr(0, j) ^ p == s.substr(s.length() - j, s.length())) {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
}