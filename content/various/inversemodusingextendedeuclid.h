

/**
 * Author: Nill
 * Date: 2025(Happy New Year)
 * License: LOL
 * Source: Hello @everyone.
 * Description: Example structures and functions that doesn't really do
 *  anything. Latex commands are supported here, though! Like this: $2^2=3$
 * Usage:
 * Status: Untested
 */

#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

pair<int, int> Extended_Euclid(int a, int b) {
    if (b == 0)
        return {1, 0};
    pair<int, int> r = Extended_Euclid(b, a % b);
    return {r.second, r.first - r.second * (a / b)};
}

int inverseMod(int a) {
    pair<int, int> ans = Extended_Euclid(a, mod);
    return ans.first;
}

int main() {
    int a; cin >> a;
    cout << inverseMod(a);
}