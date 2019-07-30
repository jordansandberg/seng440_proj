#include <stdio.h>
#include <stdlib.h>
int main() {
    char *HE_LUT[33] = { 
        "0",//A
        "110",//B
        "1110",//C
        "111110",//D
        "1111110",//E
        "11111111111111111111111111111111", // transition to next array
        "11111110",///G
        "111111110",//H
        "1111111110",//I
        "11111111111111111111111111111110",//J
        "11111111110",//K
        "10",//L
        "11111111111110",//M
        "111111111111110",//N
        "11110",//0
        "1111111111111110",//P
        "11111111111111110", //Q
        "111111111111111110",//R
        "1111111111111111110",//S
        "1111111111110",//T
        "11111111111111111110",//U
        "111111111111111111110",//V
        "1111111111111111111110",//W
        "111111111111111111111110",//X
        "1111111111111111111111110",//Y
        "11111111111111111111111110",//Z
        "111111111111111111111111110", //[
        "11111111111111111111110",// '\'
        "1111111111111111111111111110",//]
        "11111111111111111111111111110",//^
        "111111111111111111111111111110",//_
        "1111111111111111111111111111110",//g
        "111111111110"//a
    };

    char *HE_LUT2[25] = {
        "111111111111111111110",//b
        "10", //c
        "110",//d
        "1110", //e
        "111110",//f
        "0",// F
        "1111110",//h
        "11111110",//i
        "1111111110",//j
        "11111111110",//k
        "111111111110",//l
        "1111111111110",//m
        "11111111111110",//n
        "11110",//o
        "111111111111110",//p
        "111111110",//q
        "1111111111111110",//r
        "11111111111111110",//s
        "111111111111111110",//t
        "1111111111111111110",//u
        "11111111111111111110",//v
        "1111111111111111111110",//w
        "11111111111111111111110",//x
        "111111111111111111111110",//y
        "111111111111111111111111"//z
    };

    char HE_LUT_SYM[58] = {
        'A',
        'B',
        'C',
        'D',
        'E',
        '\0',
        'G',
        'H',
        'I',
        'J',
        'K',
        'L',
        'M',
        'N',
        'O',
        'P',
        'Q',
        'R',
        'S',
        'T',
        'U',
        'V',
        'W',
        'X',
        'Y',
        'Z',
        '[',
        '\\',
        ']',
        '^',
        '_',
        'g',
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
        'F',
        'h',
        'i',
        'j',
        'k',
        'l',
        'm',
        'n',
        'o',
        'p',
        'q',
        'r',
        's',
        't',
        'u',
        'v',
        'w',
        'x',
        'y',
        'z'
    };
   
    char* bitstream = (char*)malloc(sizeof(char)*500000);
    register char *barrel_shifter = (char*)malloc(32*sizeof(char*));
    int accumulator = 0, i, j;
    scanf("%s",bitstream); 
    while(1){
        // fill barrel_shifter
        if(bitstream[accumulator] == '\0') {
            printf("\n");
            break;
        }
        for(i = accumulator, j = 0; i < 32 + accumulator; i++,j++){
            barrel_shifter[j] = bitstream[i];
        }
        // do strcmpr on lut strings
        for(i=0, j=0; i<33; i++, j=0) {
            while(barrel_shifter[j] == HE_LUT[i][j]){
                if(barrel_shifter[j] == '0' || HE_LUT[i][j] == '0') break;
                j++;
            }
            // if string equal, print char
            if(barrel_shifter[j] == '0' && HE_LUT[i][j] == '0') {
                printf("%c", HE_LUT_SYM[i]);
                accumulator += j+1;
                break;
            }
        }
        // if string not equal and is all 1's break and refill barrel shifter 
        // and do strcmp on next lut
        if(i == 33){
            accumulator += 32;
            for(i = accumulator, j = 0; i < 32 + accumulator; i++,j++){
                barrel_shifter[j] = bitstream[i];
            }
            for(i=0, j=0; i<25; i++,j=0) {
                while(barrel_shifter[j] == HE_LUT2[i][j]){
                    if(barrel_shifter[j] == '0' || HE_LUT2[i][j] == '0') break;
                    j++;
                }
                // if string equal, print char
                if(barrel_shifter[j] == '0' && HE_LUT2[i][j] == '0') {
                    printf("%c", HE_LUT_SYM[i + 33]);
                    accumulator += j+1;
                    break;
                }
                else if(i == 24){
                    printf("z");
                    accumulator += j+1;
                    break;  
                }
            }          
        }
    }

    free(bitstream);
    free(barrel_shifter);
    return EXIT_SUCCESS;
}