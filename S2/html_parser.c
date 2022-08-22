#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_ERROR_MSG "File open failure"

const char tags[10][9] = {"html", "title", "body", "h1", "h2", "h3", "h4", "h5", "h6", "p"};

void betweentag(FILE *input, FILE *output){
    char currchar = fgetc(input);
    char* currTag = calloc(1, sizeof(char));
    while((currchar = fgetc(input)) != '>'){
        currTag = realloc(currTag, sizeof(currTag) + sizeof(char));
        strncat(currTag, &currchar, 1);
    }
    int valid = 0;
    for(int i = 0; i < 10; i ++) if(strcasecmp(currTag, tags[i]) == 0) valid = 1;
    free(currTag);
    while(1){
        if((currchar = fgetc(input)) == '<'){
            if((currchar = fgetc(input)) != '/') {
                ungetc(currchar, input);
                ungetc('<', input);
                betweentag(input, output);
            } else{
                while((currchar = fgetc(input)) != '>');
                return;
            }
        } else if(valid) fprintf(output, "%c", currchar);
    }
}

int main(int argc, const char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s <filename> <action>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if(file == NULL){
        fprintf(stderr, "%s\n", FILE_ERROR_MSG);
        return 2;
    }
    FILE *out = fopen(argv[2], "w");
    while(1) {
        char currchar = fgetc(file);
    	if(currchar == EOF){
        	fclose(file);
    	    fclose(out);
        	return 0;
    	}
        if(currchar == '<'){
            ungetc(currchar, file);
            betweentag(file, out);
        }
    }
    
    return 0;
}