#include <stdio.h>

int main() {
    int num = 1;        // 整数変数
    int *pnum = &num;   // int へのポインタ
    int **ppnum = &pnum; // int* へのポインタ

    // 変数のアドレスと値を表示
    printf("(void*)&num: %p, num: %d\n", (void*)&num, num);
    printf("(void*)&pnum: %p, (void*)pnum: %p, *pnum: %d\n", (void*)&pnum, (void*)pnum, *pnum);
    printf("(void*)&ppnum: %p, (void*)ppnum: %p, (void*)*ppnum: %p, **ppnum: %d\n", (void*)&ppnum, (void*)ppnum, (void*)*ppnum, **ppnum);

    return 0;
}
