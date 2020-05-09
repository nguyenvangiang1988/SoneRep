#include "main.h"

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char ch;
    char s[50];
    char sen[50];
    scanf("%c", &ch);
    scanf("%s\n", s);
    scanf("%[^\n]%*c", sen);
    printf("%c\n%s\n%s", ch, s, sen);
    return 0;
}
