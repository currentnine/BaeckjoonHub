#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, g, s;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> g >> s;

        if (g == 1) {  // 남학생
            for (int j = 1; j <= n; j++) {
                if (j % s == 0) v[j] = !v[j];
            }
        } else if (g == 2) {  // 여학생
            v[s] = !v[s];
            for (int j = 1; ; j++) {
                if (s + j > n || s - j < 1) break;
                if (v[s + j] != v[s - j]) break;
                v[s + j] = !v[s + j];
                v[s - j] = !v[s - j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
        if (i % 20 == 0) cout << "\n";
    }
}
