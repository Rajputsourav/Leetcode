#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool isValid(char* s) 
{
    
    int n = strlen(s);
    char *stack = (char *) malloc (n * sizeof(char));
    int top = -1;
    
    for(int i=0;i<n;i++)
    {
          char ch = s[i];
          if(ch =='(' || ch=='[' ||ch=='{')
          {
              stack[++top]=ch;
          }
          else {
            if (top == -1)
            {
                return false;
            }
            char open = stack[top--];
            if ((ch==')' && open !='(')  || (ch==']' && open!= '[')  || (ch=='}' && open !='{')){
                return false;
            }
        }
    }
    bool ans = (top == -1);
    return ans;
}