#include <bits/stdc++.h>
using namespace std;

bool canTurnOff(string bulbs, int x, int k) {
    int n = bulbs.size();
    int ops = 0;

    for (int i = 0; i < n; ) {
        if (bulbs[i] == '1') {
            ops++;
            i += x;   // skip x bulbs
        } else {
            i++;
        }
    }

    return ops <= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    string bulbs;
    cin >> bulbs;

    int left = 1, right = n;
    int ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canTurnOff(bulbs, mid, k)) {
            ans = mid;
            right = mid - 1;  // try smaller x
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
}
