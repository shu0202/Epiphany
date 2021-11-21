#include <iostream>
#include <cmath>
#include <string>
#include <ncurses.h>
#include <stdlib.h>
#include "newgame.h"
using namespace std;

void print_map(int map_no, int xpos, int ypos){
    clear();
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (i == ypos and j == xpos){
                printw("* ");
            }
            else{
                printw(". ");
            }
        }
        printw("\n");
        refresh();
    }
    return;
}