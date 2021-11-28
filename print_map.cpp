#include <iostream>
#include <cmath>
#include <string>
#include <ncurses.h>
#include <stdlib.h>
using namespace std;

void print_map(char map[30][30], int xpos, int ypos){
    clear();
    printw("  ");
    for (int i=0; i<30; i++){
        printw("_ ");
    }
    printw("\n");
    for (int i=0; i<30; i++){
        printw("| ");
        for (int j=0; j<30; j++){
            if (i == ypos and j == xpos){
                printw("@ ");
            }
            else{
                printw("%c ",map[i][j]);
            }
        }
        printw("|\n");
        refresh();
    }
    printw("  ");
    for (int i=0; i<30; i++){
        printw("- ");
    }
    printw("\n");
    refresh();
    return;
}