#include<bits/stdc++.h>

using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    queue<int> q1, q2, q3;
    for (int i = 0; i < n1; i++) { int n; cin >> n; q1.push(n); }
    for (int i = 0; i < n2; i++) { int n; cin >> n; q2.push(n); }

    while (!q1.empty() && !q2.empty()) {
        int a1 = q1.front(), a2 = q2.front();

        if (a1 < a2) { q3.push(a1); q3.push(a2); q1.pop(); }
        else { q3.push(a2); q3.push(a1); q2.pop(); }
    }

    while (!q1.empty()) { q3.push(q1.front()); q1.pop(); }
    while (!q2.empty()) { q3.push(q2.front()); q2.pop(); }

    while (!q3.empty()) {cout << q3.front() << "\n"; q3.pop();}
}
