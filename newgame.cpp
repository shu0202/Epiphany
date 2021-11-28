#include <iostream>
#include <cmath>
#include <string>
#include <ncurses.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "monster.h"
#include "newgame.h"
using namespace std;


void print_choice(int choice){
    clear();
    if (choice == 1){
        printw("Please choose one of the powerups below:\n");
        printw("Sword    <--\n");
        printw("Potion\n");
        printw("Gun\n");
        refresh();
    }
    else if (choice == 2){
        printw("Please choose one of the powerups below:\n");
        printw("Sword\n");
        printw("Potion   <--\n");
        printw("Gun\n");
        refresh();
    }
    else if (choice == 3){
        printw("Please choose one of the powerups below:\n");
        printw("Sword\n");
        printw("Potion\n");
        printw("Gun      <--\n");
        refresh();
    }
    return;
}

int cave_op(player_stat *player){
    int ch;
    int choice = 1;
    clear();
    ch = 0;
    print_choice(choice);
    while (ch!=10){
        if (ch == 259){
            choice = choice - 1;
            if (choice < 1){
                choice = choice + 3;
            }
            print_choice(choice);
        }
        else if (ch == 258){
            choice = choice + 1;
            if (choice > 3){
                choice = choice - 3;
            }
            print_choice(choice);
        }
        else if (ch == 261){
            choice = 3;
            print_choice(choice);
        }
        else if (ch == 260){
            choice = 1;
            print_choice(choice);
        }
        ch = getch();
    }
    if (choice == 1){
        printw("Your choice is a sword, your attack has increased by 50\nPress any key to go back to map.");
        player->atk = player->atk + 50;
        getch();
    }
    else if(choice == 2){
        printw("Your choice is a potion, your hp has been restored\nPress any key to go back to map.");
        player->hp = 200;
        getch();
    }
    else if(choice == 3){
        printw("Your choice is a gun, your critical chance has increased\nPress any key to go back to map.");
        player->crit_chance = 50;
        getch();
    }
    return 1;
}

void newgame(){
    clear();
    int alive_array[10] = {0};
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
    // get player name and initiallise player stats
    player_stat* player1 = new player_stat;
    printw("What is ur name?\n");
    refresh();
    getstr(player1->name);
    refresh();
    printw("Hello %s, welcome to epithany\n",player1->name);
    refresh();
    player1->atk = 50;
    player1->hp = 200;
    player1->crit_chance = 0.1;
    printw("Storytelling\n");
    refresh();
    printw("Press any key to continue");
    getch();
    clear();

    //decleare monsters
    monster* flower = new monster;
    strcpy(flower->name, "Flower");
    flower->no = 1;
    flower->hp = 100;
    flower->atk = 2;
    strcpy(flower->dead, "You will suffer!!!!!!!!!");
    strcpy(flower->talk, "Thank you, kind man!");

    monster* robot = new monster;
    strcpy(robot->name, "Robot");
    robot->no = 2;
    robot->hp = 200;
    robot->atk = 30;
    strcpy(robot->dead, "I...I...will...remember...you......");
    strcpy(robot->talk, "Thank you for understanding me.");

    monster* fishbone = new monster;
    strcpy(fishbone->name, "Fishbone");
    fishbone->no = 3;
    fishbone->hp = 100;
    fishbone->atk = 50;
    strcpy(fishbone->dead, "I will engrave my name in your bones.");
    strcpy(fishbone->talk, "Hope you like my fishbone crackers!");

    monster* flameboi = new monster;
    strcpy(flameboi->name, "Flameboi");
    flameboi->no = 4;
    flameboi->hp = 50;
    flameboi->atk = 250;
    strcpy(flameboi->dead, "I will burn you to ashes");
    strcpy(flameboi->talk, "Lets enjoy marshmellow later!");

    monster* bigstone = new monster;
    strcpy(bigstone->name, "Bigstone");
    bigstone->no = 5;
    bigstone->hp = 250;
    bigstone->atk = 20;
    strcpy(bigstone->dead, "I will crush your dreams!");
    strcpy(bigstone->talk, "You are my true love");

    monster* doggo = new monster;
    strcpy(doggo->name, "Doggo");
    doggo->no = 6;
    doggo->hp = 100;
    doggo->atk = 50;
    strcpy(doggo->dead, "This is animal abuse!!");
    strcpy(doggo->talk, "Can I be your pet?");

    monster* shoemaker = new monster;
    strcpy(shoemaker->name, "Shoemaker");
    shoemaker->no = 7;
    shoemaker->hp = 100;
    shoemaker->atk = 100;
    strcpy(shoemaker->dead, "Lick my shoe!!!!!");
    strcpy(shoemaker->talk, "Do you want a new shoe, I can make you one.");

    monster* iceboi = new monster;
    strcpy(iceboi->name, "Iceboi");
    iceboi->no = 8;
    iceboi->hp = 150;
    iceboi->atk = 50;
    strcpy(iceboi->dead, "Your cells will die in the breeze!");
    strcpy(iceboi->talk, "Do you want any cold drink?");

    monster* birdman = new monster;
    strcpy(birdman->name, "Birdman");
    birdman->no = 9;
    birdman->hp = 100;
    birdman->atk = 50;
    strcpy(birdman->dead, "Gok~~~~(Dies sadily)");
    strcpy(birdman->talk, "Gok Gok Gok (Flies away happily)");

    monster* bruce = new monster;
    strcpy(bruce->name, "Bruce");
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
    int cave = 0;

    print_map(map,xpos,ypos);
    while (true){
        int f = 0;
        int battle_result;
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
            if (((xpos == 3 and ypos == 25) or (xpos == 4 and ypos == 25) or (xpos == 4 and ypos == 26))and cave == 0){
                cave = cave_op(player1);
                f = 1;
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
            if (((xpos == 3 and ypos == 25) or (xpos == 4 and ypos == 25) or (xpos == 4 and ypos == 26))and cave == 0){
                cave = cave_op(player1);
                f = 1;
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
            if (((xpos == 3 and ypos == 25) or (xpos == 4 and ypos == 25) or (xpos == 4 and ypos == 26))and cave == 0){
                cave = cave_op(player1);
                f = 1;
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
            if (((xpos == 3 and ypos == 25) or (xpos == 4 and ypos == 25) or (xpos == 4 and ypos == 26))and cave == 0){
                cave = cave_op(player1);
                f = 1;
            }
            print_map(map,xpos,ypos);
        }

        if (f == 0 and monlist.size() != 0 and s!= 0){
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
                vector<int>::iterator itr;
                itr = lower_bound(monlist.begin(),monlist.end(),monem);
                monlist.erase(itr);
                // in game monster battle
                if (monem == 1 && mon_d[0] == 0){
                    
                    printw("Monster encountered is flower: %d\n",monem);
                    printw("Press any key to enter battle\n");
                    refresh();
                    getch();
                    battle_result = inbattle(player1,flower);
                    if (battle_result == 0){
                        xpos = 29;
                        ypos = 0;
                        printmap(map,xpos,ypos);
                        continue;
                    }
                    else if (battle_result == 1){
                        delete flower;
                        mon_d[0] = 1;
                    }
                    else if (battle_result == 2){
                        delete flower;
                        alive_array[0] = 1;
                        mon_d[0] = 1;
                    }
                }
                
                else if (monem == 2 && mon_d[1] == 0){
                    printw("Monster encountered is robot: %d",monem);
                    printw("Press any key to enter battle\n");
                    refresh();
                    getch();
                    battle_result = inbattle(player1,robot);
                    if (battle_result == 0){
                        xpos = 29;
                        ypos = 0;
                        printmap(map,xpos,ypos);
                        continue;
                    }
                    else if (battle_result == 1){
                        delete robot;
                        mon_d[1] = 1;
                    }
                    else if (battle_result == 2){
                        delete robot;
                        alive_array[1] = 1;
                        mon_d[1] = 1;
                    }
                }
                
                else if (monem == 3 && mon_d[2] == 0){
                    printw("Monster encountered is fishbone: %d",monem);
                    printw("Press any key to enter battle\n");
                    refresh();
                    getch();
                    battle_result = inbattle(player1,fishbone);
                    if (battle_result == 0){
                        xpos = 29;
                        ypos = 0;
                        printmap(map,xpos,ypos);
                        continue;
                    }
                    else if (battle_result == 1){
                        delete fishbone;
                        mon_d[2] = 1;
                    }
                    else if (battle_result == 2){
                        delete fishbone;
                        alive_array[2] = 1;
                        mon_d[2] = 1;
                    }
                }
                else if (monem == 4 && mon_d[3] == 0){
                    printw("Monster encountered is flameboi: %d",monem);
                    printw("Press any key to enter battle\n");
                    refresh();
                    getch();
                    battle_result = inbattle(player1,flameboi);
                    if (battle_result == 0){
                        xpos = 29;
                        ypos = 0;
                        printmap(map,xpos,ypos);
                        continue;
                    }
                    else if (battle_result == 1){
                        delete flameboi;
                        mon_d[3] = 1;
                    }
                    else if (battle_result == 2){
                        delete flameboi;
                        alive_array[3] = 1;
                        mon_d[3] = 1;
                    }
                }
                else if (monem == 5 && mon_d[4] == 0){
                    printw("Monster encountered is bigstone: %d",monem);
                    printw("Press any key to enter battle\n");
                    refresh();
                    getch();
                    battle_result = inbattle(player1,bigstone);
                    if (battle_result == 0){
                        xpos = 29;
                        ypos = 0;
                        printmap(map,xpos,ypos);
                        continue;
                    }
                    else if (battle_result == 1){
                        delete bigstone;
                        mon_d[4] = 1;
                    }
                    else if (battle_result == 2){
                        delete bigstone;
                        alive_array[4] = 1;
                        mon_d[4] = 1;
                    }
                }
                else if (monem == 6 && mon_d[5] == 0){
                    printw("Monster encountered is doggo: %d",monem);
                    printw("Press any key to enter battle\n");
                    refresh();
                    getch();
                    battle_result = inbattle(player1,doggo);
                    if (battle_result == 0){
                        xpos = 29;
                        ypos = 0;
                        printmap(map,xpos,ypos);
                        continue;
                    }
                    else if (battle_result == 1){
                        delete doggo;
                        mon_d[5] = 1;
                    }
                    else if (battle_result == 2){
                        delete doggo;
                        alive_array[5] = 1;
                        mon_d[5] = 1;
                    }
                }
                else if (monem == 7 && mon_d[6] == 0){
                    printw("Monster encountered is shoemaker: %d",monem);
                    printw("Press any key to enter battle\n");
                    refresh();
                    getch();
                    battle_result = inbattle(player1,shoemaker);
                    if (battle_result == 0){
                        xpos = 29;
                        ypos = 0;
                        printmap(map,xpos,ypos);
                        continue;
                    }
                    else if (battle_result == 1){
                        delete shoemaker;
                        mon_d[6] = 1;
                    }
                    else if (battle_result == 2){
                        delete shoemaker;
                        alive_array[6] = 1;
                        mon_d[6] = 1;
                    }
                }
                else if (monem == 8 && mon_d[7] == 0){
                    printw("Monster encountered is iceboi: %d",monem);
                    printw("Press any key to enter battle\n");
                    refresh();
                    getch();
                    battle_result = inbattle(player1,iceboi);
                    if (battle_result == 0){
                        xpos = 29;
                        ypos = 0;
                        printmap(map,xpos,ypos);
                        continue;
                    }
                    else if (battle_result == 1){
                        delete iceboi;
                        mon_d[7] = 1;
                    }
                    else if (battle_result == 2){
                        delete iceboi;
                        alive_array[7] = 1;
                        mon_d[7] = 1;
                    }
                }
                else if (monem == 9 && mon_d[8] == 0){
                    printw("Monster encountered is birdman: %d",monem);
                    printw("Press any key to enter battle\n");
                    refresh();
                    getch();
                    battle_result = inbattle(player1,birdman);
                    if (battle_result == 0){
                        xpos = 29;
                        ypos = 0;
                        printmap(map,xpos,ypos);
                        continue;
                    }
                    else if (battle_result == 1){
                        delete birdman;
                        mon_d[8] = 1;
                    }
                    else if (battle_result == 2){
                        delete birdman;
                        alive_array[8] = 1;
                        mon_d[8] = 1;
                    }
                }
                else if (monem == 10 && mon_d[9] == 0){
                    printw("Monster encountered is bruce: %d",monem);
                    printw("Press any key to enter battle\n");
                    refresh();
                    getch();
                    battle_result = inbattle(player1,bruce);
                    if (battle_result == 0){
                        xpos = 29;
                        ypos = 0;
                        printmap(map,xpos,ypos);
                        continue;
                    }
                    else if (battle_result == 1){
                        delete bruce;
                        mon_d[9] = 1;
                    }
                    else if (battle_result == 2){
                        delete bruce;
                        alive_array[9] = 1;
                        mon_d[9] = 1;
                    }
                }
                printw("\n");

            }
        }
        s=1;
        printw("pos : %d, %d\n",xpos, ypos);
        ch = getch();
        
    }
    getch();
    return;
}
