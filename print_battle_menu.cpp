#include <iostream>
#include <ncurses.h>
#include "monster.h"
#include "newgame.h"
using namespace std;

void print_battle_menu(int battlechoice, player_stat *player, monster *mon){
    if (battlechoice == 0){
        printw(" Your turn:\n");
        printw(" ___  ___  ___  ___  ___  ___  ___  ___ \n");
        printw(" %s Hp: %3d\n", mon->name, mon->hp);
        printw(" %s Hp: %3d\n", player->name, player->hp);
        printw(" Attack<--\n");
        printw(" Talk\n");
        printw(" ___  ___  ___  ___  ___  ___  ___  ___ \n");
        refresh();
    }
    else if (battlechoice == 1){
        printw(" Your turn:\n");
        printw(" ___  ___  ___  ___  ___  ___  ___  ___ \n");
        printw(" %s Hp: %3d\n", mon->name, mon->hp);
        printw(" %s Hp: %3d\n", player->name, player->hp);
        printw(" Attack\n");
        printw(" Talk<--\n");
        printw(" ___  ___  ___  ___  ___  ___  ___  ___ \n");
        refresh();
    }
}
