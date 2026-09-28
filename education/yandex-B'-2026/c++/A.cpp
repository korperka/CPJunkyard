#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    queue<int> a;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push(x);
    }

    vector<string> ans;
    stack<int> b;
    int c = 1, k = 0, m = 0;
    while (!a.empty() || !b.empty()) {
        int x = (a.empty() ? -1 : a.front()), y = (b.empty() ? -1 : b.top());

        if (y == c) {
            b.pop();
            c++; m++;
            continue;
        }
        if (m > 0) {
            ans.push_back("2 " + to_string(m));
            m = 0;
        }

        if (x == -1) {
            cout << 0;
            return 0;
        }

        a.pop();
        b.push(x);
        k++;

        if (x == c) {
            ans.push_back("1 " + to_string(k));
            k = 0;
        }
    }
    if (m > 0) {
        ans.push_back("2 " + to_string(m));
        m = 0;
    }

    cout << ans.size() << "\n";
    for (string s : ans) cout << s << "\n";
}
