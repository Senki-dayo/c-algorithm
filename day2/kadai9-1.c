#include <stdio.h>
#include <string.h>

void main(){
    char word[100];
    int i,len;
    printf("input a word\n");
    scanf("%s",word);
    len = strlen(word);
    for(i=0; i<len; i++){
        word[len*2-i-1]=word[i];
    }
    word[len*2]='\0';
    printf("%s\n",word);
    return;
}
