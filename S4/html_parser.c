#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_ERROR_MSG "File open failure"

const char lvl1[1][11] = {"html"};
const char lvl2[2][11] = {"title", "body"};
const char lvl3[10][11] = {"h1", "h2", "h3", "h4", "h5", "h6", "p", "ul", "ol", "section"};
const char lvl4[18][11] = {"li", "b", "i", "strong", "em", "small", "code", "pre", "sub",
                           "sup", "a", "label", "blockquote", "div", "cite", "addr"};
const char entities[13][2][6] = {{"nbsp", "#160"}, {"lt", "#60"}, {"gt", "#62"},
                                 {"amp", "#38"}, {"quot", "#34"}, {"apos", "#39"},
                                 {"cent", "#162"}, {"pound", "#163"}, {"yen", "#165"},
                                 {"euro", "#8364"}, {"copy", "#169"}, {"reg", "#174"}, {"sect", "#167"}};
const char replace[13][10] = {"", "<", ">", "&", "\"", "\'", "cent", "pound", "yen", "euro",
                              "copyright", "trademark", "section"};
int htmlcheck = 0;
int bodycheck = 0;

char* betweentag(int level, FILE *input){
    char currchar = fgetc(input);
    int counter1 = 1;
    char* currTag = calloc(1, sizeof(char));
    int counter2 = 1;
    char* validbuffer = calloc(1, sizeof(char));
    int counter3 = 1;
    char* buffer = calloc(1, sizeof(char));
    int counter4 = 1;
    char* endTag = calloc(1, sizeof(char));
    int valid = 0;
    int valid1 = 0;
    int valid2 = 0;
    int valid3 = 0;
    int valid4 = 0;
    if((currchar = fgetc(input)) == '/'){
        free(currTag);
        free(validbuffer);
        free(buffer);
        free(endTag);
        return NULL;
    }
    ungetc(currchar, input);
    while(1){
        if((currchar = fgetc(input)) == '>') break;
        ungetc(currchar, input);
        if((currchar = fgetc(input)) == ' '){
            if(strcasecmp(currTag, lvl1[0]) == 0) valid1 = 1;
            for(int i = 0; i < 2; i ++) if(strcasecmp(currTag, lvl2[i]) == 0) valid2 = 1;
            for(int i = 0; i < 10; i ++) if(strcasecmp(currTag, lvl3[i]) == 0) valid3 = 1;
            for(int i = 0; i < 18; i ++) if(strcasecmp(currTag, lvl4[i]) == 0) valid4 = 1;
            if(valid1 || valid2 || valid3 || valid4) valid = 1;
            switch(level){
                case 1:
                    if(valid){ if(valid1){
                        if(!htmlcheck) htmlcheck = 1;
                        else{
                            free(currTag);
                            free(validbuffer);
                            free(buffer);
                            free(endTag);
                            return NULL;
                        }
                    } else{
                        free(currTag);
                        free(validbuffer);
                        free(buffer);
                        free(endTag);
                        return NULL;
                    }}
                    break;
                case 2:
                    if(valid){ if(valid2){
                        if(strcasecmp(currTag, lvl2[1]) == 0){
                            if(!bodycheck) bodycheck = 1;
                            else{
                                free(currTag);
                                free(validbuffer);
                                free(buffer);
                                free(endTag);
                                return NULL;
                            }
                        }
                    } else{
                        free(currTag);
                        free(validbuffer);
                        free(buffer);
                        free(endTag);
                        return NULL;
                    }}
                    break;
                case 3:
                    if(valid) if(!valid3){
                        free(currTag);
                        free(validbuffer);
                        free(buffer);
                        free(endTag);
                        return NULL;
                    }
                    break;
                case 4:
                    if(valid) if(!valid4){
                        free(currTag);
                        free(validbuffer);
                        free(buffer);
                        free(endTag);
                        return NULL;
                    }
                    break;
            }
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
                    while((currchar = fgetc(input)) != '\"') {
                        if(currchar == '&'){
                            int charcounter = 1;
                            char* charentity = calloc(1, sizeof(char));
                            while((currchar = fgetc(input)) != ';'){
                                charcounter++;
                                charentity = realloc(charentity, charcounter*sizeof(char));
                                strncat(charentity, &currchar, 1);
                            }
                            int target = -1;
                            for(int i = 0; i < 13; i++) for(int j = 0; j < 2; j++){
                                if(strcasecmp(charentity, entities[i][j]) == 0) target = i;
                            }
                            free(charentity);
                            if(target != -1){
                                for(int i = 0; i < strlen(replace[target]); i ++){
                                    counter2++;
                                    validbuffer = realloc(validbuffer, counter2*sizeof(char));
                                    strncat(validbuffer, &replace[target][i], 1);
                                }
                            }
                        } else{
                            counter2++;
                            validbuffer = realloc(validbuffer, counter2*sizeof(char));
                            strncat(validbuffer, &currchar, 1);
                        }
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
    if(strcasecmp(currTag, lvl1[0]) == 0) valid1 = 1;
    for(int i = 0; i < 2; i ++) if(strcasecmp(currTag, lvl2[i]) == 0) valid2 = 1;
    for(int i = 0; i < 10; i ++) if(strcasecmp(currTag, lvl3[i]) == 0) valid3 = 1;
    for(int i = 0; i < 18; i ++) if(strcasecmp(currTag, lvl4[i]) == 0) valid4 = 1;
    if(valid1 || valid2 || valid3 || valid4) valid = 1;
    switch(level){
        case 1:
            if(valid){ if(valid1){
                if(!htmlcheck) htmlcheck = 1;
                else{
                    free(currTag);
                    free(validbuffer);
                    free(buffer);
                    free(endTag);
                    return NULL;
                }
            } else{
                free(currTag);
                free(validbuffer);
                free(buffer);
                free(endTag);
                return NULL;
            }}
            break;
        case 2:
            if(valid){ if(valid2){
                if(strcasecmp(currTag, lvl2[1]) == 0){
                    if(!bodycheck){
                        bodycheck = 1;
                    } else{
                        free(currTag);
                        free(validbuffer);
                        free(buffer);
                        free(endTag);
                        return NULL;
                    }
                }
            } else{
                free(currTag);
                free(validbuffer);
                free(buffer);
                free(endTag);
                return NULL;
            }}
            break;
        case 3:
            if(valid) if(!valid3){
                free(currTag);
                free(validbuffer);
                free(buffer);
                free(endTag);
                return NULL;
            }
            break;
        case 4:
            if(valid) if(!valid4){
                free(currTag);
                free(validbuffer);
                free(buffer);
                free(endTag);
                return NULL;
            }
            break;
    }
    while(1){
        if((currchar = fgetc(input)) == '<'){
            if((currchar = fgetc(input)) != '/') {
                int counter = 1;
                char* next = calloc(1, sizeof(char));
                counter++;
                next = realloc(next, counter*sizeof(char));
                strncat(next, &currchar, 1);
                while((currchar = fgetc(input)) != '>'){
                    counter++;
                    next = realloc(next, counter*sizeof(char));
                    strncat(next, &currchar, 1);
                }
                ungetc('>', input);
                for(int i = strlen(next)-1; i > -1; i--) ungetc(next[i], input);
                ungetc('<', input);
                switch(level){
                    case 1:
                        if(strcasecmp(next, lvl1[0]) == 0){
                            free(next);
                            free(currTag);
                            free(validbuffer);
                            free(buffer);
                            free(endTag);
                            buffer = calloc(1, sizeof(char));
                            return buffer;
                        }
                        break;
                    case 2:
                        for(int i = 0; i < 2; i ++) if(strcasecmp(next, lvl2[i]) == 0){
                            free(next);
                            free(currTag);
                            free(validbuffer);
                            free(buffer);
                            free(endTag);
                            buffer = calloc(1, sizeof(char));
                            return buffer;
                        }
                        break;
                    case 3:
                        for(int i = 0; i < 10; i ++) if(strcasecmp(next, lvl3[i]) == 0){
                            free(next);
                            free(currTag);
                            free(validbuffer);
                            free(buffer);
                            free(endTag);
                            buffer = calloc(1, sizeof(char));
                            return buffer;
                        }
                        break;
                    case 4:
                        for(int i = 0; i < 18; i ++) if(strcasecmp(next, lvl4[i]) == 0){
                            free(next);
                            free(currTag);
                            free(validbuffer);
                            free(buffer);
                            free(endTag);
                            buffer = calloc(1, sizeof(char));
                            return buffer;
                        }
                        break;
                }
                free(next);
                char* temp = betweentag(level+1, input);
                if(temp == NULL){
                    free(currTag);
                    free(validbuffer);
                    free(buffer);
                    free(endTag);
                    return NULL;
                }
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
                    if(valid){
                        free(buffer);
                        return NULL;
                    }
                    return buffer;
                }
            }
        } else{
            if(valid){
                if(currchar == '&'){
                    int charcounter = 1;
                    char* charentity = calloc(1, sizeof(char));
                    while((currchar = fgetc(input)) != ';'){
                        charcounter++;
                        charentity = realloc(charentity, charcounter*sizeof(char));
                        strncat(charentity, &currchar, 1);
                    }
                    int target = -1;
                    for(int i = 0; i < 13; i++) for(int j = 0; j < 2; j++){
                        if(strcasecmp(charentity, entities[i][j]) == 0) target = i;
                    }
                    free(charentity);
                    if(target != -1){
                        for(int i = 0; i < strlen(replace[target]); i ++){
                            counter2++;
                            validbuffer = realloc(validbuffer, counter2*sizeof(char));
                            strncat(validbuffer, &replace[target][i], 1);
                        }
                    }
                } else{
                    counter2++;
                    validbuffer = realloc(validbuffer, counter2*sizeof(char));
                    strncat(validbuffer, &currchar, 1);
                }
            } else {
                if(currchar == '&'){
                    int charcounter = 1;
                    char* charentity = calloc(1, sizeof(char));
                    while((currchar = fgetc(input)) != ';'){
                        charcounter++;
                        charentity = realloc(charentity, charcounter*sizeof(char));
                        strncat(charentity, &currchar, 1);
                    }
                    int target = -1;
                    for(int i = 0; i < 13; i++) for(int j = 0; j < 2; j++){
                        if(strcasecmp(charentity, entities[i][j]) == 0) target = i;
                    }
                    free(charentity);
                    if(target != -1){
                        for(int i = 0; i < strlen(replace[target]); i ++){
                            counter3++;
                            buffer = realloc(buffer, counter3*sizeof(char));
                            strncat(buffer, &replace[target][i], 1);
                        }
                    }
                } else{
                    counter3++;
                    buffer = realloc(buffer, counter3*sizeof(char));
                    strncat(buffer, &currchar, 1);
                }
            }
        }
    }
}

void print_file(char* toprint, FILE *output){
    for(int i = 0; i < strlen(toprint); i ++) fprintf(output, "%c", toprint[i]);
}

void print_word_count(char * path){
    FILE *file = fopen(path, "r");
    char currchar = fgetc(file);
    if(currchar == EOF){
        fclose(file);
        return;
    } else ungetc(currchar, file);
    int arraycount = 1;
    char** array = calloc(1, sizeof(char*));
    int counter = 1;
    char* word = calloc(1, sizeof(char));
    while ((currchar = fgetc(file)) != EOF){
        if(isalnum(currchar)){
            counter++;
            word = realloc(word, counter*sizeof(char));
            strncat(word, &currchar, 1);
        } else{
            if(strlen(word) != 0){
                int duplicate = 0;
                for(int i = 1; i < arraycount; i++){
                    if(strcasecmp(word, array[i]) == 0) duplicate = 1;
                }
                if(duplicate){
                    free(word);
                    counter = 1;
                	word = calloc(1, sizeof(char));
                } else{
                    arraycount++;
                	array = realloc(array, arraycount*sizeof(char*));
                	array[arraycount-1] = word;
                	counter = 1;
                	word = calloc(1, sizeof(char));
                }
            }
        }
    }
    if(strlen(word) != 0){
        arraycount++;
        array = realloc(array, arraycount*sizeof(char*));
        array[arraycount-1] = word;
        counter = 1;
        word = calloc(1, sizeof(char));
    }
    free(word);
    for(int i = 0; i < arraycount; i++) free(array[i]);
    free(array);
    fclose(file);
    printf("Word Count: %d.\n", arraycount-1);
}

void print_freq_count(char * path, char* tocheck){
    FILE *file = fopen(path, "r");
    char currchar = fgetc(file);
    if(currchar == EOF){
        fclose(file);
        return;
    } else ungetc(currchar, file);
    int frequency = 0;
    int counter = 1;
    char* word = calloc(1, sizeof(char));
    while ((currchar = fgetc(file)) != EOF){
        if(isalnum(currchar)){
            counter++;
            word = realloc(word, counter*sizeof(char));
            strncat(word, &currchar, 1);
        } else{
            if(strlen(word) != 0){
                if(strcasecmp(word, tocheck) == 0) frequency++;
                free(word);
                counter = 1;
                word = calloc(1, sizeof(char));
            }
        }
    }
    if(strlen(word) != 0){
        if(strcasecmp(word, tocheck) == 0) frequency++;
    }
    free(word);
    fclose(file);
    printf("%s Frequency: %d.\n", tocheck, frequency);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s <filename> <action>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[argc-2], "r");
    if(file == NULL){
        fprintf(stderr, "%s\n", FILE_ERROR_MSG);
        return 2;
    }
    FILE *out = fopen(argv[argc-1], "w");
    char* buffer;
    while(1){
        char currchar = fgetc(file);
    	if(currchar == EOF){
        	fclose(file);
    	    fclose(out);
            switch(argc){
                case 4:
                    print_word_count(argv[3]);
                    break;
                case 5:
                    print_freq_count(argv[4], argv[2]);
                    break;
                case 6:
                    if(strcasecmp(argv[1], "-c") == 0){
                        print_word_count(argv[5]);
                        print_freq_count(argv[5], argv[3]);
                    } else{
                        print_word_count(argv[5]);
                        print_freq_count(argv[5], argv[2]);
                    }
                    break;
            }
        	return 0;
    	}
        if(currchar == '<'){
            ungetc(currchar, file);
            buffer = betweentag(1, file);
            if(buffer != NULL){
                if(htmlcheck || bodycheck){
                    print_file(buffer, out);
                }
                free(buffer);
            } else{
                fclose(out);
                out = fopen(argv[argc-1], "w");
            }
        }
    }
    return 0;
}