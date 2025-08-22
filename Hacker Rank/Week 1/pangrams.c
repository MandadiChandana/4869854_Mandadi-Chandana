#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* pangrams(char* s) {
    int letters[26] = {0};
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = tolower(s[i]);
        if (ch >= 'a' && ch <= 'z') {
            int index = ch - 'a';
            if (!letters[index]) {
                letters[index] = 1;
                count++;
                if (count == 26) {
                    break;
                }
            }
        }
    }

    if (count == 26) {
        return "pangram";
    } else {
        return "not pangram";
    }
}

int main() {
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 1;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    char* result = pangrams(buffer);
    printf("%s\n", result);

    return 0;
}
