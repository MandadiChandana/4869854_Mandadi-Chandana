#include <stdio.h>

int towerBreakers(int n, int m) {
    if (m == 1) {
        return 2;
    } else if (n % 2 == 0) {
        return 2;
    } else {
        return 1;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%d\n", towerBreakers(n, m));
    }
    return 0;
}
