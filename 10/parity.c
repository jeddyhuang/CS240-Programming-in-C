#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_ERROR_MSG "File open failure\n"
#define FORMAT_ERROR_MSG "File format violation\n"

int main(int argc, const char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    if(file == NULL){
        fprintf(stderr, "%s", FILE_ERROR_MSG);
        return 1;
    }
    char curr = fgetc(file);
    if(curr == EOF){
        fclose(file);
        return 0;
    }
    int count = 1;
    while((curr = fgetc(file)) != EOF) count++;
    fclose(file);
    if((count % (4*8)) != 0){
        fprintf(stderr, "%s", FORMAT_ERROR_MSG);
        return 2;
    }
    file = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    while((curr = fgetc(file)) != EOF){
        ungetc(curr, file);
        unsigned char toadd = 0x00;
        for(int i = 0; i < 8; i ++){
            int parity = 0;
        	for(int j = 0; j < 4; j ++){
                int parity1 = 0;
                curr = fgetc(file);
            	fprintf(out, "%c", curr);
            	for(int n = 0; n < 8; n++) parity1 ^= (curr >> n) & 1;
                parity ^= parity1 & 1;
        	}
            toadd = toadd >> 1;
            if(parity) toadd = toadd | 0x80;
        }
        fprintf(out, "%c", toadd);
    }
    fclose(file);
    fclose(out);
    
    return 0;
}