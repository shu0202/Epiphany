#include <iostream>
using namespace std;

void make_prop(char map[30][30]){
    for (int i=0; i<15; i++){
        map[0][i] = '^';
    }
    for (int i=15; i<30; i++){
        map[0][i] = '.';
    }
    for (int i=0; i<14; i++){
        map[1][i] = '^';
    }
    map [1][14] = '~';
    //for (int i=0; )

    return;
}
