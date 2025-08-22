#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    int* result = malloc(queries_count * sizeof(int));
    for (int i = 0; i < queries_count; i++) {
        int count = 0;
        for (int j = 0; j < strings_count; j++) {
            if (strcmp(queries[i], strings[j]) == 0) {
                count++;
            }
        }
        result[i] = count;
    }
    *result_count = queries_count;
    return result;
}

int main() {
    int strings_count;
    scanf("%d", &strings_count);
    
    char** strings = malloc(strings_count * sizeof(char*));
    for (int i = 0; i < strings_count; i++) {
        strings[i] = malloc(1001); // allocate max 1000 characters + 1
        scanf("%s", strings[i]);
    }

    int queries_count;
    scanf("%d", &queries_count);

    char** queries = malloc(queries_count * sizeof(char*));
    for (int i = 0; i < queries_count; i++) {
        queries[i] = malloc(1001);
        scanf("%s", queries[i]);
    }

    int result_count;
    int* results = matchingStrings(strings_count, strings, queries_count, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", results[i]);
    }

    // Free memory
    for (int i = 0; i < strings_count; i++) {
        free(strings[i]);
    }
    for (int i = 0; i < queries_count; i++) {
        free(queries[i]);
    }
    free(strings);
    free(queries);
    free(results);

    return 0;
}
