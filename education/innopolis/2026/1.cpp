#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const int INF = 1e9+1;

int mod(ll a, ll m) {
    return (a % m + m) % m;
}

string bfs(int v1, int v2, int m, int n) {
    vector<int> d(n, -1);
    vector<int> p(n, -1);
    queue<int> q;

    if (v1 == v2) return "";

    d[v1] = 0;
    q.push(v1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int c : {mod(u+m, n), mod(u-m, n), mod(1LL*u*m, n)}) {
            if (d[c] == -1) {
                d[c] = d[u]+1;
                q.push(c);
                p[c] = u;
            }
        }
    }

    if (d[v2] == -1) {
        return ".";
    }

    vector<int> s;
    for (int v = v2; v != -1; v = p[v]) {
        s.push_back(v);
    }

    reverse(s.begin(), s.end());

    string ans;
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i+1] == mod(s[i]+m, n)) ans += '+';
        else if (s[i+1] == mod(s[i]-m, n)) ans += '-';
        else if (s[i+1] == mod(1LL*s[i]*m, n)) ans += '*';
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll a, m, b, n; cin >> a >> m >> b >> n;

    ll v = mod(mod(a, m), n);
    a = mod(a, n); b = mod(b, n);

    if (a == b) {
        cout << 0;
        return 0;
    }

    string s1= bfs(a, b, m, n), s2 = bfs(v, b, m, n), s3 = bfs(0, b,  m, n);
    int k = min(s1 == "." ? INF : s1.size(), min(s2 == "." ? INF : s2.size()+1, s3 == "." ? INF : s3.size()+2));

    if (s1.size() == k) cout << k << "\n" << s1;
    else if (s2.size()+1 == k) cout << k << "\n" << "%" << s2;
    else if (s3.size()+2 == k) cout << k << "\n" << "*%" << s3;
    else cout << -1;
}