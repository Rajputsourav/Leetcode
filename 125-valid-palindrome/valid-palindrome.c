#include<ctype.h>
bool isPalindrome(char* s) {
    int left =0;
    int right =0;

    while(s[right] !='\0')
    {
        right ++;
    }
    right --;

    while(left < right){
        while (left< right && ! isalnum(s[left]))
        {
            left ++;
        }
        while(left < right && ! isalnum(s[right]))
        {
            right --;
        }
        if(tolower(s[left]) != tolower(s[right])){
            return false ;
        }
        left ++;
        right --;
    }
    return true;
}