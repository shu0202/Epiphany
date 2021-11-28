// newgame.h

#ifndef NEWGAME_H
#define NEWGAME_H

void print_map(char map[30][30], int xpos, int ypos);
void make_prop(char map [30][30]);
int inbattle(player_stat *player, monster *mon);

#endif