#include "beer_song.h"

void recite(unsigned int start_bottles, unsigned int take_down, char *buffer) {
    // notice: you will get an error if you don't initialize it before strcat
    buffer[0] = '\0'; 
    
    const char ca_bottles[]        = "%s bottle%s of beer";
    const char ca_on_the_wall []   = " on the wall";
    const char ca_take_and_pass [] = "Take %s down and pass %s around, ";
    const char ca_it[]                  = "it";
    const char ca_one[]                 = "one";
    // Decided to insert "%s"s here in order to squeeze in the ifblock
    const char ca_buy_some_more [] = "Go to the store and buy %s %s, "; 
    const char ca_no_more[] = "no more";
    const char ca_No_more[] = "No more";

    #define ifblock(val, s, f1, f2, f3, subs11, subs12, subs21, subs22, subs31, subs32)\
        if        (val > 1) {\
            sprintf(s, f1, subs11, subs12);\
        } else if (val == 1) {\
            sprintf(s, f2, subs21, subs22);\
        } else {\
            sprintf(s, f3, subs31, subs32);\
        }

    // To avoid the error of comparing different types.
    int i_start = start_bottles; 
    int i_take_down = take_down;
    for (int i = i_start, j = 0; i >=0 && j < i_take_down; --i, j++) {
        char verse[140];           
        char s[100];               
        char ca_num_of_bottles[3]; 
        // Initialization Block:
        // (notice: you will get an error if you don't initialize verse)
        {
            verse[0] = '\0';
            s[0] = '\0';
            ca_num_of_bottles[0] = '\0';
        }
    
        //first line
        sprintf(ca_num_of_bottles, "%d", i);
        ifblock(i, s, ca_bottles, ca_bottles, ca_bottles, ca_num_of_bottles,
         "s",ca_num_of_bottles, "", ca_No_more, "s");
        strcat(verse, strcat(strcat(s, ca_on_the_wall), ", "));
        
        ifblock(i, s, ca_bottles, ca_bottles, ca_bottles, ca_num_of_bottles,
         "s", ca_num_of_bottles, "", ca_no_more, "s");
        strcat(verse, strcat(s, ".\n"));
        
        //second line
        ifblock(i, s, ca_take_and_pass, ca_take_and_pass, ca_buy_some_more, 
         ca_one, ca_it, ca_it, ca_it, "some", "more");
        strcat(verse, s);
        
        int bottles_left = i >= 1 ? i - 1 : 99;
        sprintf(ca_num_of_bottles, "%d", bottles_left);
        ifblock(bottles_left, s, ca_bottles, ca_bottles, ca_bottles, ca_num_of_bottles,
         "s", ca_num_of_bottles, "", ca_no_more, "s");
        strcat(verse, strcat(strcat(s, ca_on_the_wall), ".\n"));
        
        strcat(buffer, verse);
        if (j >= 0 && j < i_take_down-1) strcat(buffer, "\n");
    }

    #undef ifblock
}