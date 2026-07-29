int strStr(char *haystack, char *needle) {

    int i = 0, j = 0;

    if (needle[0] == '\0')
        return 0;

    while (haystack[i] != '\0') {

        j = 0;

        while (haystack[i + j] != '\0' &&
               needle[j] != '\0' &&
               haystack[i + j] == needle[j]) {
            j++;
        }

        if (needle[j] == '\0')
            return i;

        i++;
    }

    return -1;
}