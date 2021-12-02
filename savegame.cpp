#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>
#include "monster.h"
#include "savegame.h"
using namespace std;

int savegame(player_stat *player, vector<int> monlist, int xpos, int ypos, int cave, int alive[10]){
    clear();
    int ch;
    int choice = 1;
    printw("Save & Exit   <--\n");
    printw("Exit\n");
    refresh();
    ch = getch();
    while (ch != 10){
        if (ch == 259){
            choice = choice - 1;
            if (choice < 1){
                choice = 2;
            }
        }
        else if (ch == 258){
            choice = choice - 1;
            if (choice > 2){
                choice = 1;
            }
        }
        else if (ch == 261){
            choice = 2;
        }
        else if (ch == 260){
            choice = 1;
        }

        if (choice == 1){
            clear();
            printw("Save & Exit   <--\n");
            printw("Exit\n");
            refresh();
        }
        else {
            clear();
            printw("Save & Exit\n");
            printw("Exit          <--\n");
            refresh();
        }
        ch = getch();
    }
    if (choice == 1){
        ofstream outputf;
        outputf.open("epiphany_save.txt");
        outputf << player->name << endl;
        outputf << player->hp << endl;
        outputf << player->atk << endl;
        outputf << player->crit_chance << endl;
        outputf << xpos << " " << ypos << endl;
        outputf << cave << endl;
        outputf << monlist.size() << endl;
        for (int i=0;i<monlist.size();i++){
            outputf << monlist[i] << endl;
        }
        for (int i=0;i<10;i++){
            outputf << alive[i] << endl;
        }
        outputf.close();
        return 0;
    }
    else {
        return 0;
    }


}