#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    unordered_set<int> dp[9];

    for (int i = 1; i <= 8; i++) {
        int repeated = 0;

        // 5 -> 55 -> 555 -> 5555 ...
        for (int j = 0; j < i; j++) {
            repeated = repeated * 10 + N;
        }

        dp[i].insert(repeated);

        for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);

                    if (b != 0) {
                        dp[i].insert(a / b);
                    }
                }
            }
        }

        if (dp[i].find(number) != dp[i].end()) {
            return i;
        }
    }

    return -1;
}