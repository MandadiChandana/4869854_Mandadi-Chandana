#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

char* twoArrays(int k, int A_count, int* A, int B_count, int* B) {
    qsort(A, A_count, sizeof(int), compare_asc);
    qsort(B, B_count, sizeof(int), compare_desc);

    for (int i = 0; i < A_count; i++) {
        if (A[i] + B[i] < k) {
            return "NO";
        }
    }
    return "YES";
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    if (!data) return NULL;

    while (1) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;
        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;
        alloc_length <<= 1;
        char* new_data = realloc(data, alloc_length);
        if (!new_data) {
            free(data);
            return NULL;
        }
        data = new_data;
    }
    if (data_length > 0 && data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }
    return data;
}

char* ltrim(char* str) {
    while (*str && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    int spaces = 0;
    char** splits = NULL;
    char* token = strtok(str, " ");
    while (token) {
        char** temp = realloc(splits, sizeof(char*) * (spaces + 1));
        if (!temp) {
            free(splits);
            return NULL;
        }
        splits = temp;
        splits[spaces++] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}

int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    if (!fptr) return 1;

    char* q_str = readline();
    int q = parse_int(ltrim(rtrim(q_str)));
    free(q_str);

    for (int i = 0; i < q; i++) {
        char* first_line = readline();
        char** first_input = split_string(ltrim(rtrim(first_line)));

        int n = parse_int(first_input[0]);
        int k = parse_int(first_input[1]);

        free(first_line);
        free(first_input);

        char* A_line = readline();
        char** A_temp = split_string(ltrim(rtrim(A_line)));
        int* A = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            A[j] = parse_int(A_temp[j]);
        }
        free(A_line);
        free(A_temp);

        char* B_line = readline();
        char** B_temp = split_string(ltrim(rtrim(B_line)));
        int* B = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            B[j] = parse_int(B_temp[j]);
        }
        free(B_line);
        free(B_temp);

        char* result = twoArrays(k, n, A, n, B);
        fprintf(fptr, "%s\n", result);

        free(A);
        free(B);
    }

    fclose(fptr);
    return 0;
}
