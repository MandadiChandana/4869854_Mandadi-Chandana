#include <stdio.h>
#include <stdlib.h>

int sockMerchant(int n, int* ar) {
    int pairs = 0;
    int count[101] = {0};
    for (int i = 0; i < n; i++) {
        count[ar[i]]++;
    }
    for (int i = 0; i < 101; i++) {
        pairs += count[i] / 2;
    }
    return pairs;
}

int main() {
    int n;
    scanf("%d", &n);
    int* ar = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    int ans = sockMerchant(n, ar);
    printf("%d\n", ans);
    free(ar);
    return 0;
}
