#include <stdio.h>

long calculateSumLoop(int n) {
    long total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

long calculateSumRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return n + calculateSumRecursive(n - 1);
}

int main() {
    int target = 10;
    
    printf("ผลรวม (Loop) ของ %d คือ: %ld\n", target, calculateSumLoop(target));
    printf("ผลรวม (Recursive) ของ %d คือ: %ld\n", target, calculateSumRecursive(target));
    
    return 0;
}
