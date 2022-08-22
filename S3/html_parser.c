#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_ERROR_MSG "File open failure"

const char tags[30][11] = {"html", "title", "body", "h1", "h2", "h3", "h4", "h5", "h6", "p",
                           "li", "ul", "ol", "b", "i", "strong", "em", "small", "code", "pre",
                           "sub", "sup", "q", "cite", "section", "a", "label", "abbr", "blockquote", "div"};

char* betweentag(FILE *input){
    char currchar = fgetc(input);
    int counter1 = 1;
    char* currTag = calloc(1, sizeof(char));
    int counter4 = 1;
    char* endTag = calloc(1, sizeof(char));
    int counter2 = 1;
    char* validbuffer = calloc(1, sizeof(char));
    int counter3 = 1;
    char* buffer = calloc(1, sizeof(char));
    int valid = 0;
    while(1){
        if((currchar = fgetc(input)) == '>') break;
        ungetc(currchar, input);
        if((currchar = fgetc(input)) == ' '){
            for(int i = 0; i < 30; i ++) if(strcasecmp(currTag, tags[i]) == 0) valid = 1;
            if(valid){
                int counter = 1;
                char* attribute = calloc(1, sizeof(char));
                while((currchar = fgetc(input)) != '='){
                    counter++;
                    attribute = realloc(attribute, counter*sizeof(char));
                    strncat(attribute, &currchar, 1);
                }
                if(strcasecmp(attribute, "title") == 0){
                    while((currchar = fgetc(input)) != '\"');
                    while((currchar = fgetc(input)) != '\\' && currchar != '\"') {
                        counter2++;
                        validbuffer = realloc(validbuffer, counter2*sizeof(char));
                        strncat(validbuffer, &currchar, 1);
                    }
                    counter2++;
                    validbuffer = realloc(validbuffer, counter2*sizeof(char));
                    char temp = ' ';
                    strncat(validbuffer, &temp, 1);
                }
                free(attribute);
                while((currchar = fgetc(input)) != '>');
                ungetc(currchar, input);
            }
        } else {
            counter1++;
            currTag = realloc(currTag, counter1*sizeof(char));
            strncat(currTag, &currchar, 1);
        }
    }
    for(int i = 0; i < 30; i ++) if(strcasecmp(currTag, tags[i]) == 0) valid = 1;
    while(1){
        if((currchar = fgetc(input)) == '<'){
            if((currchar = fgetc(input)) != '/') {
                ungetc(currchar, input);
                ungetc('<', input);
                char* temp = betweentag(input);
                counter3 += strlen(temp);
                buffer = realloc(buffer, counter3*sizeof(char));
                counter2 += strlen(temp);
                validbuffer = realloc(validbuffer, counter2*sizeof(char));
                strncat(buffer, temp, strlen(temp));
                strncat(validbuffer, temp, strlen(temp));
                free(temp);
            } else{
                while((currchar = fgetc(input)) != '>'){
                    counter4++;
                    endTag = realloc(endTag, counter4*sizeof(char));
                    strncat(endTag, &currchar, 1);
                }
                if(strcasecmp(endTag, currTag) == 0){
                    free(currTag);
                    free(endTag);
                    free(buffer);
                    return validbuffer;
                } else{
                    ungetc('>', input);
                    for(int i = strlen(endTag)-1; i > -1; i--) ungetc(endTag[i], input);
                    ungetc('/', input);
                    ungetc('<', input);
                    free(currTag);
                    free(endTag);
                    free(validbuffer);
                    return buffer;
                }
            }
        } else{
            if(valid){
            	counter2++;
                validbuffer = realloc(validbuffer, counter2*sizeof(char));
                strncat(validbuffer, &currchar, 1);
            } else {
                counter3++;
                buffer = realloc(buffer, counter3*sizeof(char));
                strncat(buffer, &currchar, 1);
            }
        }
    }
}

void print_file(char* toprint, FILE *output){
    for(int i = 0; i < strlen(toprint); i ++) fprintf(output, "%c", toprint[i]);
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
    char* buffer;
    while(1) {
        char currchar = fgetc(file);
    	if(currchar == EOF){
        	fclose(file);
    	    fclose(out);
        	return 0;
    	}
        if(currchar == '<'){
            ungetc(currchar, file);
            buffer = betweentag(file);
            print_file(buffer, out);
            free(buffer);
        }
    }
    
    return 0;
}