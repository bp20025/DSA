#include <stdio.h>
#include <string.h>

#define MAX 100

int match(int m, int n, char X[], char Y[]) {
    int dp[MAX][MAX] = {0};

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i] == Y[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    char X[MAX], Y[MAX];
    strcpy(X, " bacab");  // 添え字1から始まるように先頭に空白を追加
    strcpy(Y, " cbcba");  // 同上
    // char X[] = {' ', 'b', 'a', 'c', 'a', 'b'}; // 1-based index, ' ' is a placeholder
    // char Y[] = {' ', 'c', 'b', 'c', 'b', 'a'}; // 1-based index

    int m = strlen(X) - 1; // Length excluding placeholder
    int n = strlen(Y) - 1; // Length excluding placeholder

    int length = match(m, n, X, Y);
    printf("Length of longest common subsequence: %d\n", length);

    return 0;
}
