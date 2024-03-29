#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ncurses.h>
#include "monster.h"
#include "loadgame.h"
using namespace std;

int loadgame(player_stat *player, vector<int> &monlist, int &xpos, int &ypos, int &cave, int alive[10]){
    //read the saved file and load it into the current game
    clear();
    int j;
    int monlist_size;
    char filename[20] = "epiphany_save.txt";
    ifstream fin;
    fin.open(filename);
    if (fin.fail()){
        printw("Save file missing\n");
        refresh();
        getch();
        endwin();
        exit(1);
    }
    fin >> player->name;
    fin >> player->hp;
    fin >> player->atk;
    fin >> player->crit_chance;
    fin >> xpos >> ypos;
    fin >> cave;
    fin >> monlist_size;
    for (int k = 0; k < monlist_size; k++){
        fin >> j;
        monlist.push_back(j);
    }
    for (int i = 0; i < 10; i++){
        fin >> alive[i];
    }

    fin.close();
    return 0;
}
