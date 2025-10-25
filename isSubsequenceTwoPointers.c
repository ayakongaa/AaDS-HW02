#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "abd";
    char b[] = "uabqd";

    int i = 0; // указатель для a
    int j = 0; // указатель для b

    int len_a = strlen(a);
    int len_b = strlen(b);

    while (i < len_a && j < len_b) {
        if (a[i] == b[j])
            i++;
        j++;
    }

    if (i == len_a) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}
