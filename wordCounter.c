#include <stdio.h>
#include <stdbool.h>

//Checks for whitespaces, gives permission for the program
//to count new words upon finding a whitespace.
int whitespaceChecker(char c, bool *p){
    if(c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\f'){
        *p = true;
        return 1;
    }
    else
        return 0;
}

int main(){
    FILE *f = fopen("PUT FILE LOCATION HERE","r");
    int count = 0;
    bool perm = true; //Perm as in permission (for increasing the counter)
    char ch;

    //Checks every letter of the file. If it's not a whitespace and the program has permission
    //to count, then increase the wordcount and immidiately disable permission. In practice, the
    //program is increasing wordcount upon finding the first letter of each word.
    while((ch = fgetc(f)) != EOF){
        if(whitespaceChecker(ch, &perm) == 0 && perm == true){
            count++;
            perm = false;
        }
    }
    printf("Counted %d words.\n", count);

    return 0;
}