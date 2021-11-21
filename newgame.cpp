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
    monster* flower = new monster;
    flower->hp = 100;
    flower->atk = 2;
    strcpy(flower->dead, "U will suffer!!!!!!!!!");
    strcpy(flower->talk, "Thank you, kind man!");
    printw("Flower:\n   Hp: %d\n    Atk: %d\n   Die: %s\n   Talk: %s\n",flower->hp,flower->atk,flower->dead,flower->talk);
    getch();
    clear();

    print_map(map_no,xpos,ypos);
    while (true){
        if (ch == 259){
            ypos = ypos - 1;
            if (ypos < 0){
                ypos = ypos + 10;
            }
            print_map(map_no,xpos,ypos);
        }
        else if (ch == 258){
            ypos = ypos + 1;
            if (ypos > 9){
                ypos = ypos - 10;
            }
            print_map(map_no,xpos,ypos);
        }
        else if (ch == 261){
            xpos = xpos + 1;
            if (xpos > 9){
                xpos = xpos - 10;
            }
            print_map(map_no,xpos,ypos);
        }
        else if (ch == 260){
            xpos = xpos - 1;
            if (xpos < 0){
                xpos = xpos + 10;
            }
            print_map(map_no,xpos,ypos);
        }
        ch = getch();
    }
    getch();
    return;
}