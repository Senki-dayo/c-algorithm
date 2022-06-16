#include <stdio.h>

void main(){
    char line[100], name[100], birth[100], address[100], phone[100];
    FILE *in_file;

    in_file = fopen("Book1.txt","r");
    if (in_file == NULL){
        return;
    }
    while(fgets(line,100,in_file) != NULL) {
        sscanf(line,"%s %s %s %s",name,birth,address,phone);
        printf("name = %s\nbirth = %s\naddress = %s\nphone = %s\n\n",name,birth,address,phone);
    }
    fclose(in_file);
    return;
}