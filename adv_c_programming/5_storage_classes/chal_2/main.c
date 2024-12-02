#include <stdint.h>
#include <stdio.h>

int sum(int num){
    static int total;
    total += num;
    return total;
}

int main() {
    printf("%d ", sum(10));
    printf("%d ", sum(20));
    printf("%d ", sum(30));
    return 1;
}