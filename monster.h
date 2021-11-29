#ifndef MY_STRUCT
#define MY_STRUCT

struct monster{
    char name[20];
    int no;
    int hp;
    int atk;
    char dead[200];
    char talk[200];
    // Every monster has equal crit chance of 0.1;
};

struct player_stat{
    int hp;
    int atk;
    double crit_chance;
    char name[30];
};

#endif

