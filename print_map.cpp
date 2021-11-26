#include <iostream>
#include <cmath>
#include <string>
#include <ncurses.h>
#include <stdlib.h>
#include "newgame.h"
using namespace std;

void print_map(char map[30][30], int xpos, int ypos){
    clear();
    for (int i=0; i<30; i++){
        //printw("%d",i);
        for (int j=0; j<30; j++){
            if (i == ypos and j == xpos){
                printw("@ ");
            }
            else{
                printw("%c ",map[i][j]);
            }
        }
        printw("\n");
        refresh();
    }
    return;
}