                  
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

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

auto start = high_resolution_clock::now();
#define int long long

bool marked[1000001];
vector<int> primes;

void sieve(int n) {
    memset(marked, false, n+1);
    marked[1] = true;
    for (int i = 4; i <= n; i += 2)
        marked[i] = true;
    for (int i = 3; i*i <= n; i += 2) {
        if (!marked[i]) {
            for (int j = i*i; j <= n; j += i*2)
                marked[j] = true;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (!marked[i])
            primes.push_back(i);
    }
}

int32_t main() {
    int a, b; cin >> a >> b;
    int n = sqrt(b);
    sieve(n);
    vector<int> rangePrimes;
    int segments = ceil(sqrt(b-a+1));
    int low = a, high = a + segments - 1;
    for (int i = 0; i < segments; ++i) {
        int range = high - low + 1;
        memset(marked, false, range);
        for (auto j : primes) {
            for (int k = max(j*j, (low+j-1)/j * j); k <= high; k += j)
                marked[k-low] = true;
        }
        
        if (low == 1)
            marked[0] = true;
        for (int j = 0; j < range; ++j) {
            if (!marked[j])
                rangePrimes.push_back(j+low);
        }
        low = high + 1;
        high = min(b, high + segments);
    }
    
    cout << "Total Primes: " << rangePrimes.size();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds> (stop - start);
    cout << "\nTime Taken: " << duration.count() << " milliseconds.";
}