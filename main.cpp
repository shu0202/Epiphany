#include <iostream>
#include <cmath>
#include <string>
#include <ncurses.h>
#include <stdlib.h>
#include "main.h"
using namespace std;

int main(){
    int ch;
    int choice = 1;
    int ex = 0;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    print_menu(choice);         //print main menu
    ch = getch();               //use arrows to control the user's choice
    while (ch != 10){

        if (ch == 259){
            choice = choice - 1;
            if (choice < 1){
                choice = choice + 3;
            }
            print_menu(choice);
        }
        else if (ch == 258){
            choice = choice + 1;
            if (choice > 3){
                choice = choice - 3;
            }
            print_menu(choice);
        }
        else if (ch == 261){
            choice = 3;
            print_menu(choice);
        }
        else if (ch == 260){
            choice = 1;
            print_menu(choice);
        }
        ch = getch();
    }
    switch(choice){
        case 1:
            //printw("NewGame");
            newgame();          //enter new game
            endwin();
            break;
        case 2:
            printw("LoadGame");
            getch();
            endwin();
            break;
            //loadgame();
        case 3:
            getch();
            break;
            endwin();
    }
    return 0;
}