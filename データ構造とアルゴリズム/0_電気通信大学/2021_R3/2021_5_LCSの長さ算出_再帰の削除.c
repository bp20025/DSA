// 電気通信大学 2019
// LCS（最長共通部分列）の長さ算出

#include <stdio.h>
#include <string.h>

#define MAX 1000

int LCS(char X[], char Y[], int m, int n) {
    int L[m+1][n+1];
    int i, j;

    // Fill the LCS table in a bottom-up manner
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];
        }
    }

    // L[m][n] contains the length of LCS for X[0..m-1], Y[0..n-1]
    return L[m][n];
}

int main() {
    char X[MAX], Y[MAX];
    strcpy(X, "bacab");  // 添え字1から始まるように先頭に空白を追加
    strcpy(Y, "cbcba");  // 同上

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", LCS(X, Y, m, n));
    return 0;
}

