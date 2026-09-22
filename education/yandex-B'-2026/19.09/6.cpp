#include <iostream>
#include <stack>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    ll n;
    cin >> n;

    vector<ll> p;
    while (n--) {
        char c;
        cin >> c;

        if (c == '+') {
            int v;
            cin >> v;
            p.push_back(v);
        } else if (c == '-') {
            cout << p.back() << "\n";
            p.pop_back();
        } else {
            int v, sum = 0; cin >> v;
            for (int i = 1; i <= v; i++) {
                sum += p[p.size()-i];
            }

            cout << sum << "\n";
        }
    }
}
