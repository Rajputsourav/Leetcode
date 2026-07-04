#include<string.h>
#include<ctype.h>
// #include <stdbool.h>

bool isPalindrome(char* s) {
    int slen = strlen(s);
    char temp[slen+1];
    temp[0] = '\0';
    char ch[2];

    for (int i = 0; i < slen; i++) {
        if (isalnum(s[i])) {
            ch[0] = tolower(s[i]);
            ch[1] = '\0';
            strncat(temp, ch, 1);
        }
    }

    int start = 0, end = strlen(temp)-1; 

    while(start<end){
        if(temp[start]!= temp[end]) return false;
        start++;
        end--;
    }


    return true;
    
}