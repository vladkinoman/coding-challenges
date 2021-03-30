#include "beer_song.h"

void recite(unsigned int start_bottles, unsigned int take_down, char *buffer) {
    buffer[0] = '\0';
    int i_start = start_bottles;
    int i_take_down = take_down;
    for (int i = i_start, j = 0; i >=0 && j < i_take_down; --i, j++) {
        char verse[140];
        if (i > 1) {
            sprintf(verse, "%u bottles of beer on the wall, %u bottles of beer.\n"
                "Take one down and pass it around, ", i, i);
            if (i == 2) {
                strcat(verse, "1 bottle of beer on the wall.\n");
            } else {
                char ending[40];
                sprintf(ending, "%u bottles of beer on the wall.\n", i-1);
                strcat(verse, ending);
            }
        } else if (i == 1) {
            sprintf(verse, "1 bottle of beer on the wall, 1 bottle of beer.\n"
                "Take it down and pass it around, no more bottles of beer on the wall.\n");
        } else {
            sprintf(verse, "No more bottles of beer on the wall, no more bottles of beer.\n"
            "Go to the store and buy some more, 99 bottles of beer on the wall.\n");
        }
        strcat(buffer, verse);
        if (j >= 0 && j < i_take_down-1) strcat(buffer, "\n");
    }
}