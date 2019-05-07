#include<iostream>
#include<cstring>
#include<cstdio>

#define MAX 1003

int main(){
    char str[MAX];
    int str_len;

    fgets(str, MAX, stdin); /// input the character array

    str_len = strlen(str); /// length of the character array

    int count_char[257];

    for(int i = 0; i<257; i++){
        count_char[i] = 0;     /// initialize count_char array with 0
    }

    for(int i = 0; i<str_len; i++){
        char ch = str[i];
        count_char[ch]++; /// increase the ch char frequency 1 base on ch ascii value  

    }
    int mx = 0, ans_fre;
    char ans_char;
    for(int i = 0; i<str_len; i++){
        char ch = str[i];
        int fre_ch = count_char[ch];

        if(fre_ch>mx){       /// find most occours character and frequency
            mx = fre_ch;
            ans_char = str[i];
            ans_fre = fre_ch;
        }
    }

    /// print the most occours character of the character array
    printf("Most occours character %c : %d\n", ans_char, ans_fre);

    /// bonus task
    char duplicate_char='0';
    for(int i = 0; i<str_len; i++){
        char ch = str[i];
        int fre_ch = count_char[ch];
        if(fre_ch>=2){               // find first duplicated char
            duplicate_char = ch;
            break;
        }
    }
    if(duplicate_char == '0'){  /// if no duplicated char found
        printf("There is no duplicated character is the character array\n");
    }else{
        printf("First occourance of a duplicated char: %c\n", duplicate_char);
    }

    return 0;
}

