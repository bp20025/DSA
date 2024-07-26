// 電気通信大学 2019
// LCS（最長共通部分列）の長さ算出

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// X[m+1], Y[n+1]の配列をグローバル変数として宣言
char X[MAX_LEN], Y[MAX_LEN];

// 再帰的に最長共通部分列の長さを求める関数
int match(int m, int n) {
    if (m == 0 || n == 0) {
        return 0;  // いずれかの文字列が空になった場合
    }

    if (X[m] == Y[n]) {
        return 1 + match(m - 1, n - 1);  // 文字が一致する場合
    } else {
        return (match(m - 1, n) > match(m, n - 1)) ? match(m - 1, n) : match(m, n - 1);  // 文字が一致しない場合
    }
}

int main() {
    strcpy(X, " bacab");  // 添え字1から始まるように先頭に空白を追加
    strcpy(Y, " cbcba");  // 同上

    int m = strlen(X) - 1;  // 実際の文字列の長さを計算
    int n = strlen(Y) - 1;  // 同上

    printf("Longest common subsequence length: %d\n", match(m, n));

    return 0;
}
