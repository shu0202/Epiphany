#include <vector>
#include <ncurses.h>
#include <iostream>
#include "tower.h"
using namespace std;

void tower(int result, int flag, vector<int> monlist, int alive[10]){
    int count=0;
    for (int i=0;i<10;i++){
        if (alive[i]==1){
            count = count + 1;
        }
    }
    if (flag==0){
        clear();
        if (monlist.size() == 10 and count == 0){
            printw("You have entered the wrong place!\n");
            refresh();
            printw("The king will fight you to test if you are the hourned one!\n");
            refresh();
            getch();
            return;
        }
        else if ((monlist.size()+count) > 5){
            printw("You have make many friends throughout your journey!\n");
            refresh();
            printw("The King will give you a final test\n");
            refresh();
            getch();
            return;
        }
        else{
            printw("You have killed many residents of this country throughout your journey!\n");
            refresh();
            printw("The King will chase you to death!!!!\n");
            refresh();
            getch();
            return;
        }
    }
    if (flag == 1){
        if ((monlist.size()+count) > 5){
            clear();
            printw("You've killed the king.\n");
            refresh();
            getch();
            printw("However, the king has sent his soilders to kill your family.\n");
            refresh();
            getch();

        }
        else if((monlist.size()+count) <= 5){
            clear();
            printw("You are a true worthy person!!!\n");
            refresh();
            getch();
            printw("You will be the warrior that live in this world and live happily ever after!\n");
            refresh();
            getch();
        }
    }
}