#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // สร้างตารางเก็บผลรวมสะสมของแนวทะแยง
    vector<vector<ll>> diag_sum(n, vector<ll>(n, 0));

    ll max_sum = LLONG_MIN;

    // คำนวณผลรวมสะสมของแนวทะแยง
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            diag_sum[i][j] = A[i][j];
            if (i + 1 < n && j + 1 < n) {
                diag_sum[i][j] += diag_sum[i + 1][j + 1];
            }
            // อัปเดตผลรวมสูงสุด
            max_sum = max(max_sum, diag_sum[i][j]);
        }
    }

    cout << max_sum << '\n';
    return 0;
}
