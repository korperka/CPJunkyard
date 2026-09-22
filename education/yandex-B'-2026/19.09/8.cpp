#include <iostream>
#include <stack>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    ll n;
    cin >> n;

    vector<int> q;
    while (n--) {
        char c;
        cin >> c;

        if (c == '+') {
            int k;
            cin >> k;
            q.push_back(k);
        } else if (c == '*') {
            int k;
            cin >> k;
            q.insert(q.begin() + (q.size() + 1) / 2, k);
        } else if (c == '-') {
            cout << q[0] << "\n";
            q.erase(q.begin());
        }
    }
}
