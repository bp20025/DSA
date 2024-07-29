#include <stdio.h>

int main() {
    int num = 1;
    int *pnum = &num;

    // pnumの値（numのアドレス）を表示
    printf("pnumの値: %p\n", (void*)pnum); // -> 0x7ffeefbff5ac
    
    // *pnumの値（numの値）を表示
    printf("*pnumの値: %d\n", *pnum); // -> 1

    return 0;
}
