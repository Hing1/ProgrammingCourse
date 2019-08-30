#include <stdio.h>
#include <string.h>

/*
s1 > s2 1
s1 = s2 0
s1 < s2 -1

依次比较字符的ASCII码
*/

/*
int myStrcmp(char * s1, char * s2){
    while (*s1 != '\0' && *s2 != '\0') {
        if(*s1 > *s2)
            return 1;
        else if(*s1 < *s2)
            return -1;
        else {
            s1 ++;
            s2 ++;
        }
    }
    if(*s1 == '\0' && *s2 != '\0')
        return -1;
    else if(*s1 != '\0' && *s2 == '\0')
        return 1;
    else
        return 0;
}
*/
/*
int myStrcmp(char * s1, char * s2){
    for (;*s1 != '\0' && *s2 != '\0';s1++,s2++) {
        if(*s1 != *s2)
            break;
    }
    return *s1 - *s2;
}*/
/*
int myStrcmp(char * s1, char * s2){
    for (;*s1 && *s2; s1++, s2++) {
        if(*s1 != *s2)
            break;
    }
    return *s1 - *s2;
}*/

int myStrcmp(char * s1, char * s2){
    for (;*s1 && *s2 && (*s1 == *s2); s1++, s2++);
    return *s1 - *s2;
}

int main()
{
    char * s1 = "ahina";
    char * s2 = "china";

    int ret = myStrcmp(s1, s2);

    printf("%d\n",ret);

    return 0;
}
