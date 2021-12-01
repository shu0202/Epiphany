#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "monster.h"
#include "loadgame.h"
using namespace std;

int loadgame(player_stat *player, vector<int> monlist, int &xpos, int &ypos, int alive[10]){
    //read the saved file and load it into the current game
    clear();
    int monlist_size;
    char filename[20] = "epiphany_save.txt";
    ifstream fin;
    fin.open(filename);
    if (fin.fail()){
        cout << "Save file missing" << endl;
        exit(1);
    }
    fin >> player->name;
    fin >> player->hp;
    fin >> player->atk;
    fin >> player->crit_chance;
    fin >> xpos >> ypos;
    fin >> monlist_size;
    for (int k = 0; k < monlist_size; k++){
        fin >> monlist[k];
    }
    for (int i = 0; i < 10; i++){
        fin >> alive[i];
    }

    fin.close();
    return 0;
}