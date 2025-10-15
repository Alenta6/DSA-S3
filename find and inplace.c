#include <stdio.h>
#include <string.h>
#include <ctype.h> 

#define MAX_TEXT 1000
#define MAX_FIND 100
#define MAX_REPLACE 100

int strncasecmp_custom(const char *s1, const char *s2, int len) {
    for (int i = 0; i < len; i++) {
        if (tolower((unsigned char)s1[i]) != tolower((unsigned char)s2[i])) {
            return (int)(tolower((unsigned char)s1[i]) - tolower((unsigned char)s2[i]));
        }
    }
    return 0;
}

void find_and_replace(char *text, const char *find, const char *replace, char *result) {
    int i = 0, j = 0;
    int len_text = strlen(text);
    int len_find = strlen(find);
    int len_replace = strlen(replace);

    while (i < len_text) {
        if (i + len_find <= len_text && strncasecmp_custom(&text[i], find, len_find) == 0) {
            for (int k = 0; k < len_replace; k++) {
                result[j++] = replace[k];
            }
            i += len_find;
        } else {
            result[j++] = text[i++];
        }
    }
    result[j] = '\0';
}

int main() {
    char text[MAX_TEXT];
    char find[MAX_FIND];
    char replace[MAX_REPLACE];
    char result[MAX_TEXT * 2]; 

    printf("Enter the text:\n");
    fgets(text, MAX_TEXT, stdin);
    text[strcspn(text, "\n")] = 0; 

    printf("\nEnter the string to find:\n");
    fgets(find, MAX_FIND, stdin);
    find[strcspn(find, "\n")] = 0;

    printf("\nEnter the string to replace with:\n");
    fgets(replace, MAX_REPLACE, stdin);
    replace[strcspn(replace, "\n")] = 0;

    find_and_replace(text, find, replace, result);

    printf("\nModified text:\n%s\n", result);

    return 0;
}