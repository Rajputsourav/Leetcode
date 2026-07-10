void reverse(char* s,int left,int right){
    while(left<right){
        char temp = s[left];
        s[left]=s[right];
        s[right]=temp;
        left++;
        right--;
    }
}

char* reverseWords(char* s) {

    int n = strlen(s);
    int i = 0,j=0;

    while(i<n){
        while(i<n&&s[i]==' '){
            i++;
        }
        while(i<n&&s[i]!=' '){
            s[j++]=s[i++];
        }
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n)
        s[j++]=' ';
    }
    n=j;
    s[j++]='\0';
    

    reverse(s,0,n-1);
    int start = 0;
    for(i = 0;i<=n;i++){
        if(s[i]==' '|| s[i]=='\0'){
            reverse(s,start,i-1);
            start= i+1;
        }
    }
    return s;
}