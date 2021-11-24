#include <iostream>
#include <cmath>
#include <string>
#include <ncurses.h>
#include <stdlib.h>
#include "newgame.h"
#include "monster.h"
using namespace std;
void newgame(){
    clear();
    int xpos = 0;
    int ypos = 0;
    int map_no = 0;
    char name[30];
    int ch;
    echo();
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
    



    getch();
    clear();

    print_map(map_no,xpos,ypos);
    while (true){
        if (ch == 259){
            ypos = ypos - 1;
            if (ypos < 0){
                ypos = ypos + 30;
            }
            print_map(map_no,xpos,ypos);
        }
        else if (ch == 258){
            ypos = ypos + 1;
            if (ypos > 29){
                ypos = ypos - 30;
            }
            print_map(map_no,xpos,ypos);
        }
        else if (ch == 261){
            xpos = xpos + 1;
            if (xpos > 29){
                xpos = xpos - 30;
            }
            print_map(map_no,xpos,ypos);
        }
        else if (ch == 260){
            xpos = xpos - 1;
            if (xpos < 0){
                xpos = xpos + 30;
            }
            print_map(map_no,xpos,ypos);
        }
        ch = getch();
    }
    getch();
    return;
}