#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ncurses.h>
#include "monster.h"
#include "newgame.h"
#include "print_battle.h"
using namespace std;

int inbattle(player_stat *player, monster *mon){
    int k, battlechoice, ch;
    double critchance, misschance;
    k = 0;
    srand(time(NULL));
    while (true){
        clear();
        misschance = ((double) rand()/RAND_MAX);
        critchance = ((double) rand()/RAND_MAX);
        if (k%2 == 0){
            //battle menu
            battlechoice = 0;
            print_battle_menu(battlechoice, player, mon);
            ch = getch();  
            while (ch != 13){
                clear();
                if (ch == 119){
                    battlechoice -= 1;
                    if (battlechoice < 0){
                        battlechoice = 1;
                    }
                    print_battle_menu(battlechoice, player, mon);
                }
                else if (ch == 115){
                    battlechoice += 1;
                    if (battlechoice > 1){
                        battlechoice = 0;
                    }
                    print_battle_menu(battlechoice, player, mon);
                }
                else
                    print_battle_menu(battlechoice, player, mon);
                ch = getch();
            }
        }
        clear();
        //player turn
        if (k % 2 == 0){
            //player chose attack
            if (battlechoice == 0){
                if (misschance <= 0.1){
                    printw("Attack missed\n");
                    k += 1;
                    printw("(Press any key to proceed to next turn...)\n");
                    refresh();
                    getch();
                    continue;
                }
                else{
                    if (critchance <= player->crit_chance){
                        printw("It's a critical hit!\n");
                        printw("%s got hit by %d\n", mon->name, (player->atk)*2);
                        refresh();
                        mon->hp -= (player->atk)*2;
                    }
                    else{
                        printw("%s got hit by %d\n", mon->name, player->atk);
                        refresh();
                        mon->hp -= player->atk;
                    }
                }
            }
            //player chose talk
            else if (battlechoice == 1){
                printw("%s: %s\n", mon->name, mon->talk);
                printw("You spared %s...\n", mon->name);
                printw("(Press any key to leave...)\n");
                refresh();
                getch();
                return 2;
            }
        }
        //monster turn
        else{
            clear();
            printw("Opponent's turn:\n");
            refresh();
            if (misschance <= 0.1){
                printw("Attack missed\n");
                k += 1;
                printw("(Press any key to proceed to next turn...)\n");
                refresh();
                getch();
                continue;
            }
            else{
                if (critchance <= 0.1){
                    printw("It's a critical hit!\n");
                    printw("%s got hit by %d\n", player->name, (mon->atk)*2);
                    refresh();
                    player->hp -= (mon->atk)*2;
                }
                else{
                    printw("%s got hit by %d\n", player->name, mon->atk);
                    refresh();
                    player->hp -= mon->atk;
                }
            }
        }
        if (player->hp <= 0){
            printw("You fainted...\n");
            printw("(Press any key to respawn...)\n");
            refresh();
            getch();
            return 0;
        }
        if (mon->hp <= 0){
            printw("%s: %s\n", mon->name, mon->dead);
            printw("You killed %s...\n", mon->name);
            printw("(Press any key to leave...)\n");
            refresh();
            getch();
            return 1;
        }
        k += 1;
        printw("(Press any key to proceed to next turn...)\n");
        refresh();
        getch();  
    }
}
