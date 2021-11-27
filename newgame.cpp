#include <iostream>
#include <cmath>
#include <string>
#include <ncurses.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "newgame.h"
#include "monster.h"
using namespace std;
void newgame(){
    clear();
    int xpos = 29;
    int ypos = 0;
    int mon_acc = 10;
    vector <int> monlist;
    char name[30];
    int ch;
    echo();
    for (int i=1; i<11; i++){
        monlist.push_back(i);
    }
    // get player name
    printw("What is ur name?\n");
    refresh();
    getstr(name);
    refresh();
    printw("Hello %s, welcome to epithany\n",name);
    refresh();
    printw("Storytelling\n");
    refresh();
    printw("Press any key to continue");
    getch();
    clear();

    //decleare monsters
    monster* flower = new monster;
    flower->no = 1;
    flower->hp = 100;
    flower->atk = 2;
    strcpy(flower->dead, "You will suffer!!!!!!!!!");
    strcpy(flower->talk, "Thank you, kind man!");

    monster* robot = new monster;
    robot->no = 2;
    robot->hp = 200;
    robot->atk = 30;
    strcpy(robot->dead, "I...I...will...remember...you......");
    strcpy(robot->talk, "Thank you for understanding me.");

    monster* fishbone = new monster;
    fishbone->no = 3;
    fishbone->hp = 100;
    fishbone->atk = 50;
    strcpy(fishbone->dead, "I will engrave my name in your bones.");
    strcpy(fishbone->talk, "Hope you like my fishbone crackers!");

    monster* flameboi = new monster;
    flameboi->no = 4;
    flameboi->hp = 50;
    flameboi->atk = 250;
    strcpy(flameboi->dead, "I will burn you to ashes");
    strcpy(flameboi->talk, "Lets enjoy marshmellow later!");

    monster* bigstone = new monster;
    bigstone->no = 5;
    bigstone->hp = 250;
    bigstone->atk = 20;
    strcpy(bigstone->dead, "I will crush your dreams!");
    strcpy(bigstone->talk, "You are my true love");

    monster* doggo = new monster;
    doggo->no = 6;
    doggo->hp = 100;
    doggo->atk = 50;
    strcpy(doggo->dead, "This is animal abuse!!");
    strcpy(doggo->talk, "Can I be your pet?");

    monster* shoemaker = new monster;
    shoemaker->no = 7;
    shoemaker->hp = 100;
    shoemaker->atk = 100;
    strcpy(shoemaker->dead, "Lick my shoe!!!!!");
    strcpy(shoemaker->talk, "Do you want a new shoe, I can make you one.");

    monster* iceboi = new monster;
    iceboi->no = 8;
    iceboi->hp = 150;
    iceboi->atk = 50;
    strcpy(iceboi->dead, "Your cells will die in the breeze!");
    strcpy(iceboi->talk, "Do you want any cold drink?");

    monster* birdman = new monster;
    birdman->no = 9;
    birdman->hp = 100;
    birdman->atk = 50;
    strcpy(birdman->dead, "Gok~~~~(Dies sadily)");
    strcpy(birdman->talk, "Gok Gok Gok (Fly away happily)");

    monster* bruce = new monster;
    bruce->no = 10;
    bruce->hp = 100;
    bruce->atk = 100;
    strcpy(bruce->dead, "Be water my friend.");
    strcpy(bruce->talk, "I will teach you zhe quan dao!");

    //adventure in map

    char map[30][30];
    make_prop(map);
    
    int mon_d[10] = {0};
    int s=0;

    print_map(map,xpos,ypos);
    while (true){
        int f = 0;
        
        if (ch == 259){
            ypos = ypos - 1;
            if (ypos < 0){
                ypos = ypos + 30;
                if (map[ypos][xpos] == '^' or map[ypos][xpos] == ' '){
                    ypos = ypos - 30 + 1;
                    f = 1;
                }
            }
            else{
                if (map[ypos][xpos] == '^' or map[ypos][xpos] == ' '){
                    ypos = ypos + 1;
                    f = 1;
                }
            }
            print_map(map,xpos,ypos);
        }
        else if (ch == 258){
            ypos = ypos + 1;
            if (ypos > 29){
                ypos = ypos - 30;
                if (map[ypos][xpos] == '^' or map[ypos][xpos] == ' '){
                    ypos = ypos + 30 - 1;
                    f = 1;
                }
            }
            else{
                if (map[ypos][xpos] == '^' or map[ypos][xpos] == ' '){
                    ypos = ypos - 1;
                    f = 1;
                }
            }
            print_map(map,xpos,ypos);
        }
        else if (ch == 261){
            xpos = xpos + 1;
            if (xpos > 29){
                xpos = xpos - 30;
                if (map[ypos][xpos] == '^' or map[ypos][xpos] == ' '){
                    xpos = xpos + 30 - 1;
                    f = 1;
                }
            }
            else{
                if (map[ypos][xpos] == '^' or map[ypos][xpos] == ' '){
                    xpos = xpos - 1;
                    f = 1;
                }
            }
            print_map(map,xpos,ypos);
        }
        else if (ch == 260){
            xpos = xpos - 1;
            if (xpos < 0){
                xpos = xpos + 30;
                if (map[ypos][xpos] == '^' or map[ypos][xpos] == ' '){
                    xpos = xpos - 30 + 1;
                    f = 1;
                }
            }
            else{
                if (map[ypos][xpos] == '^' or map[ypos][xpos] == ' '){
                    xpos = xpos + 1;
                    f = 1;
                }
            }
            print_map(map,xpos,ypos);
        }
        if (f == 0 and monlist.size() != 0){
            srand((unsigned) time(0));
            int monchance;
            int monen;
            int monem;
            monchance = (rand() % 100) + 1;
            //printw("mon chance: %d\n",monchance);
            refresh();
            if (monchance < 31){
                // delete monster
                monen = (rand() % mon_acc) + 1;
                mon_acc = mon_acc - 1;
                monem = monlist[monen-1];
                //printw("mon delete: %d\n",monem);
                //refresh();
                vector<int>::iterator itr;
                itr = lower_bound(monlist.begin(),monlist.end(),monem);
                //printw("vector list: ");
                //refresh();
                //for (int k=0;k<monlist.size();k++){
                //    printw("%d ",monlist[k]);
                //    refresh();
                //}
                //printw("\n");
                //refresh();
                monlist.erase(itr);
                //printw("erased\n");
                // in game monster battle
                if (monem == 1 && mon_d[0] == 0){
                    printw("Monster encountered is Flower: %d",monem);
                    refresh();
                    delete flower;
                    mon_d[0] = 1;
                }
                else if (monem == 2 && mon_d[1] == 0){
                    printw("Monster encountered is Robot: %d",monem);
                    refresh();
                    delete robot;
                    mon_d[1] = 1;
                }
                else if (monem == 3 && mon_d[2] == 0){
                    printw("Monster encountered is Fishbone: %d",monem);
                    refresh();
                    delete fishbone;
                    mon_d[2] = 1;
                }
                else if (monem == 4 && mon_d[3] == 0){
                    printw("Monster encountered is Flameboi: %d",monem);
                    refresh();
                    delete flameboi;
                    mon_d[3] = 1;
                }
                else if (monem == 5 && mon_d[4] == 0){
                    printw("Monster encountered is Bigstone: %d",monem);
                    refresh();
                    delete bigstone;
                    mon_d[4] = 1;
                }
                else if (monem == 6 && mon_d[5] == 0){
                    printw("Monster encountered is Doggo: %d",monem);
                    refresh();
                    delete doggo;
                    mon_d[5] = 1;
                }
                else if (monem == 7 && mon_d[6] == 0){
                    printw("Monster encountered is Shoemaker: %d",monem);
                    refresh();
                    delete shoemaker;
                    mon_d[6] = 1;
                }
                else if (monem == 8 && mon_d[7] == 0){
                    printw("Monster encountered is Iceboi: %d",monem);
                    refresh();
                    delete iceboi;
                    mon_d[7] = 1;
                }
                else if (monem == 9 && mon_d[8] == 0){
                    printw("Monster encountered is Birdman: %d",monem);
                    refresh();
                    delete birdman;
                    mon_d[8] = 1;
                }
                else if (monem == 10 && mon_d[9] == 0){
                    printw("Monster encountered is Bruce: %d",monem);
                    refresh();
                    delete bruce;
                    mon_d[9] = 1;
                }
                printw("\n");

            }
        }
        printw("pos : %d, %d\n",xpos, ypos);
        ch = getch();
        
    }
    getch();
    return;
}