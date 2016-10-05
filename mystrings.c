#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char *src){
  int len = 0;
  while (src[len] != 0){
    len++;
  }
  return len;
}

int mystrnlen(char *src, int n){
  int len = mystrlen(src);
  return (len < n ? len : n );
}

char* mystrcpy(char *dest, char *src){
  int i;
  for (i = 0; (dest[i] = src[i]) != 0; i++){
  }
  return dest;
}


char* mystrncpy(char *dest, char *src, int n){
  int i;
  for (i = 0; i < n && src[i] != 0; i++)
    dest[i] = src[i];
  for ( ; i < n; i++)
    dest[i] = 0;
  return dest;
}

char* mystrcat(char *dest, char *src){
  int len = strlen(dest);
  int i;
  for (i = 0 ; src[i] != 0 ; i++){
    dest[len + i] = src[i];
  }
  dest[len + i] = 0;
  return dest;
}

char* mystrncat(char *dest, char *src, int n){
  int len = strlen(dest);
  int i;
  for (i = 0 ; i < n && src[i] != 0 ; i++){
    dest[len + i] = src[i];
  }
  dest[len + i] = 0;
  return dest;
}

int mystrcmp(char *s, char *d){
    int i;

    for (i = 0; s[i] == d[i]; i++)
        if (s[i] == 0)
            return 0;
    return s[i] - d[i];
}

int mystrncmp(char *s, char *d, int n){
    int i;

    for (i = 0; i < n && s[i] == d[i]; i++)
        if (s[i] == 0)
            return 0;
    return s[i] - d[i];
}

char* mystrchr( char *s, char c ){
    int i = 0;
    while (s[i] != c)
        i++;
        if (s[i]==0)
            return 0;
    return (&s[i]);

}

char* mystrstr(char *haystack,char *needle) { //inefficient recursive lol
    if (needle[0]==0 || haystack[0]==0)
        return (NULL);
    if ((haystack[0] == needle[0]) && (strstr(haystack+1, needle+1) == haystack+1)) 
        return (char *)haystack;
    return strstr(haystack+1, needle);
}



int teststrlen(){
  printf("\n####################STRLEN TESTS#######################################\n\n");
  printf("(my strlen) \n Length of string \"its working\" should be 11: \n %d\n", mystrlen("its working"));
  printf("(system strlen) \n Length of string  \"its working\" should be 11: \n %d\n", strlen("its working"));
  return 0;
}

int teststrnlen(){
  printf("\n####################STRNLEN TESTS#######################################\n\n");
  printf("(my strnlen) \n Length of the string pointed to by  \"its working\", not including the terminating null character, up to a maximum of 5 bytes: \n %d\n", mystrnlen("its working",5));
  printf(" Length of the string pointed to by  \"its working\", not including the terminating null character, up to a maximum of 25 bytes: \n %d\n", mystrnlen("its working",25));
  printf("(system strnlen) \n Length of the string pointed to by  \"its working\", not including the terminating null character, up to a maximum of 5 bytes: \n %d\n", strnlen("its working",5));
  printf(" Length of the string pointed to by  \"its working\", not including the terminating null character, up to a maximum of 25 bytes: \n %d\n", strnlen("its working",25));
  return 0;
}


int teststrcpy(){
  char my[40];
  char sys[40];
  mystrcpy(my, "its working");
  strcpy(sys,  "its working");
  printf("\n####################STRCPY TESTS#######################################\n\n");
  printf("(my strcpy) \n Initial copied string \"its working\" should be copied: \n %s\n", my);
  printf("(system strcpy) \n Initial copied string  \"its working\" should be copied: \n %s\n", sys);
  return 0;
}


int teststrncpy(){
  char my[40];
  char sys[40];
  mystrncpy(my, "its workingnnnn",11);
  strncpy(sys,  "its workingnnnn",11);
  printf("\n####################STRNCPY TESTS#######################################\n\n");
  printf("(my strncpy) \n Initial copied string \"its workingnnnn\" should ------->\"its working\": \n %s\n", my);
  printf("(system strncpy) \n Initial copied string  \"its workingnnnn\" should ------->\"its working\": \n %s\n", sys);
  return 0;
}

int teststrcat(){
 char my[40] = "Hello my name is ";
 char sys[40] = "Hello my name is ";
 mystrcat(my,"Shaeq Ahmed");
 strcat(sys,"Shaeq Ahmed");
 printf("\n####################STRCAT TESTS#######################################\n\n");
 printf("(my strcat) \n Should concatenate string \"Hello my name is \" with \"Shaeq Ahmed\": \n %s\n", my);
 printf("(system strcat) \n Should concatenate string \"Hello my name is \" with \"Shaeq Ahmed\": \n %s\n", sys);
 return(0);
}

int teststrncat(){
 char my[40] = "Hello my name is ";
 char sys[40] = "Hello my name is ";
 mystrncat(my,"Shaeq Ahmednnnn",11);
 strncat(sys,"Shaeq Ahmednnnn",11);
 printf("\n####################STRNCAT TESTS#######################################\n\n");
 printf("(my strncat) \n Should concatenate string \"Hello my name is \" with first 11 char of \"Shaeq Ahmednnnn\": \n %s\n", my);
 printf("(system strncat) \n Should concatenate string \"Hello my name is \" with first 11 char of \"Shaeq Ahmednnnn\": \n %s\n", sys);
 return(0);
}


int teststrcmp(){
  printf("\n####################STRCMP TESTS#######################################\n\n");
  printf("(my strcmp) \n String \"abc\" > \"ABC\" should be positive: \n %d\n", mystrcmp("abc","ABC"));
  printf("(my strcmp) \n String \"ABC\" < \"abc\" should be negative: \n %d\n", mystrcmp("ABC","abc"));
  printf("(my strcmp) \n String \"ABC\" = \"ABC\" should be zero: \n %d\n", mystrcmp("ABC","ABC"));
  printf("(system strcmp) \n String \"abc\" > \"ABC\" should be positive: \n %d\n", strcmp("abc","ABC"));
  printf("(system strcmp) \n String \"ABC\" < \"abc\" should be negative: \n %d\n", strcmp("ABC","abc"));
  printf("(system strcmp) \n String \"ABC\" = \"ABC\" should be zero: \n %d\n", strcmp("ABC","ABC"));
  return 0;
}

int teststrncmp(){
  printf("\n####################STRNCMP TESTS#######################################\n\n");
  printf("(my strncmp) \n String \"abc\" > \"ABC\" for first 2 bytes, should be positive: \n %d\n", mystrncmp("abc","ABC",2));
  printf("(my strncmp) \n String \"ABC\" < \"abc\" for first 2 bytes, should be negative: \n %d\n", mystrncmp("ABC","abc",2));
  printf("(my strncmp) \n String \"ABC\" = \"ABC\" for first 2 bytes, should be zero: \n %d\n", mystrncmp("ABC","ABC",2));
  printf("(system strncmp) \n String \"abc\" > \"ABC\" for first 2 bytes, should be positive: \n %d\n", strncmp("abc","ABC",2));
  printf("(system strncmp) \n String \"ABC\" < \"abc\" for first 2 bytes, should be negative: \n %d\n", strncmp("ABC","abc",2));
  printf("(system strncmp) \n String \"ABC\" = \"ABC\" for first 2 bytes, should be zero: \n %d\n", strncmp("ABC","ABC",2));
  return 0;
}

int teststrchr(){
  printf("\n####################STRCHR TESTS#######################################\n\n");
  printf("(my strchr) \n First occurence of \"l\" in \"playlist\" at: \n %s\n", mystrchr("playlist",'l'));
  printf("(system strchr) \n First occurence of \"l\" in \"playlist\" at: \n %s\n", strchr("playlist",'l'));
  return 0;
}

int teststrstr(){
  printf("\n####################STRSTR TESTS#######################################\n\n");
  printf("(my strstr) \n First occurence of \"lit\" in \"belittle\" at: \n %s\n", mystrstr("belittle","lit"));
  printf("(system strchr) \n First occurence of \"lit\" in \"belittle\" at: \n %s\n", strstr("belittle","lit"));
  return 0;
}






int main(){
  teststrlen();
  teststrnlen();
  teststrcpy();
  teststrncpy();
  teststrcat();
  teststrncat();
  teststrcmp();
  teststrncmp();
  teststrchr();
  teststrstr();
  return 0;
}  