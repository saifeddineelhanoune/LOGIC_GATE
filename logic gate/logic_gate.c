#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to implement the logic gates
char* and_gate(const char* a, const char* b) {
    int len = strlen(a);
    char* result = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = (a[i] == '_' && b[i] == '_') ? '_' : '-';
    }
    result[len] = '\0';
    return result;
}

char* or_gate(const char* a, const char* b) {
    int len = strlen(a);
    char* result = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = (a[i] == '-' || b[i] == '-') ? '-' : '_';
    }
    result[len] = '\0';
    return result;
}

char* xor_gate(const char* a, const char* b) {
    int len = strlen(a);
    char* result = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = (a[i] == b[i]) ? '_' : '-';
    }
    result[len] = '\0';
    return result;
}

char* nand_gate(const char* a, const char* b) {
    int len = strlen(a);
    char* result = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = (a[i] == '_' && b[i] == '_') ? '-' : '_';
    }
    result[len] = '\0';
    return result;
}

char* nor_gate(const char* a, const char* b) {
    int len = strlen(a);
    char* result = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = (a[i] == '_' || b[i] == '_') ? '-' : '_';
    }
    result[len] = '\0';
    return result;
}

char* nxor_gate(const char* a, const char* b) {
    int len = strlen(a);
    char* result = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = (a[i] == b[i]) ? '-' : '_';
    }
    result[len] = '\0';
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    char input_names[n][9];
    char input_signals[n][65];

    // Read input signals and their data
    for (int i = 0; i < n; i++) {
        scanf("%s%s", input_names[i], input_signals[i]);
    }

    char output_names[m][9];
    char types[m][9];
    char input_name_1[m][9];
    char input_name_2[m][9];

    // Read output signals and their respective gates and input names
    for (int i = 0; i < m; i++) {
        scanf("%s%s%s%s", output_names[i], types[i], input_name_1[i], input_name_2[i]);
    }

    // Apply logic gates and print the output
    for (int i = 0; i < m; i++) {
        char* signal1;
        char* signal2;
        for (int j = 0; j < n; j++) {
            if (strcmp(input_names[j], input_name_1[i]) == 0) {
                signal1 = input_signals[j];
            }
            if (strcmp(input_names[j], input_name_2[i]) == 0) {
                signal2 = input_signals[j];
            }
        }

        char* output_data;
        if (strcmp(types[i], "AND") == 0) {
            output_data = and_gate(signal1, signal2);
        } else if (strcmp(types[i], "OR") == 0) {
            output_data = or_gate(signal1, signal2);
        } else if (strcmp(types[i], "XOR") == 0) {
            output_data = xor_gate(signal1, signal2);
        } else if (strcmp(types[i], "NAND") == 0) {
            output_data = nand_gate(signal1, signal2);
        } else if (strcmp(types[i], "NOR") == 0) {
            output_data = nor_gate(signal1, signal2);
        } else if (strcmp(types[i], "NXOR") == 0) {
            output_data = nxor_gate(signal1, signal2);
        }

        printf("%s %s\n", output_names[i], output_data);
        free(output_data);
    }

    return 0;
}
