#include <iostream>
using namespace std;

void make_prop(char map[30][30]){
    for (int i=0; i<15; i++){
        map[0][i] = '^';
    }
    for (int i=15; i<30; i++){
        map[0][i] = '.';
    }

    for (int i=0; i<15; i++){
        map[1][i] = '^';
    }
    for (int i=15; i<30;i++){
        map[1][i] = '.';
    }

    for (int i=0; i<14; i++){
        map[2][i] = '^';
    }
    map [2][14] = '~';
    for (int i=15; i<30;i++){
        map[2][i] = '.';
    }

    for (int i=0; i<14; i++){
        map[3][i] = '^';
    }
    map [3][14] = '~';
    for (int i=15; i<30;i++){
        map[3][i] = '.';
    }

    for (int i=0; i<13; i++){
        map[4][i] = '^';
    }
    map [4][13] = '~';
    map [4][14] = '~';
    for (int i=15; i<30;i++){
        map[4][i] = '.';
    }

    for (int i=0; i<12; i++){
        map[5][i] = '^';
    }
    map [5][12] = '~';
    map [5][13] = '~';
    map [5][14] = '~';
    for (int i=15; i<30;i++){
        map[5][i] = '.';
    }

    for (int i=0; i<11; i++){
        map[6][i] = '^';
    }
    map [6][11] = '~';
    map [6][12] = '~';
    map [6][13] = '~';
    map [6][14] = '~';
    for (int i=15; i<30;i++){
        map[6][i] = '.';
    }

    for (int i=0; i<11; i++){
        map[7][i] = '^';
    }
    map [7][11] = '*';
    map [7][12] = '~';
    map [7][13] = '~';
    map [7][14] = '~';
    map [7][15] = '~';
    for (int i=16; i<30;i++){
        map[7][i] = '.';
    }

    for (int i=0; i<10; i++){
        map[8][i] = '^';
    }
    map [8][10] = '*';
    map [8][11] = '*';
    map [8][12] = '~';
    map [8][13] = '~';
    map [8][14] = '~';
    map [8][15] = '~';
    for (int i=16; i<30;i++){
        map[8][i] = '.';
    }

    for (int i=0; i<9; i++){
        map[9][i] = '^';
    }
    map [9][9] = '*';
    map [9][10] = '*';
    map [9][11] = '*';
    map [9][12] = '*';
    map [9][13] = '~';
    map [9][14] = '~';
    map [9][15] = '~';
    map [9][16] = '~';
    for (int i=17; i<30;i++){
        map[9][i] = '.';
    }

    for (int i=0; i<8; i++){
        map[10][i] = '^';
    }
    map [10][8] = '*';
    map [10][9] = '*';
    map [10][10] = '*';
    map [10][11] = '*';
    map [10][12] = '*';
    map [10][13] = '*';
    map [10][14] = '~';
    map [10][15] = '~';
    map [10][16] = '~';
    map [10][17] = '~';
    for (int i=18; i<30;i++){
        map[10][i] = '.';
    }

    for (int i=0; i<7; i++){
        map[11][i] = '^';
    }
    map [11][7] = '*';
    map [11][8] = '*';
    map [11][9] = '*';
    map [11][10] = '*';
    map [11][11] = '*';
    map [11][12] = '*';
    map [11][13] = '*';
    map [11][14] = '*';
    map [11][15] = '~';
    map [11][16] = '~';
    map [11][17] = '~';
    map [11][18] = '~';
    for (int i=19; i<30;i++){
        map[11][i] = '.';
    }

    for (int i=0; i<6; i++){
        map[12][i] = '^';
    }
    map [12][6] = '*';
    map [12][7] = '*';
    map [12][8] = '*';
    map [12][9] = '*';
    map [12][10] = '*';
    map [12][11] = '*';
    map [12][12] = '*';
    map [12][13] = '*';
    map [12][14] = '*';
    map [12][15] = '*';
    map [12][16] = '~';
    map [12][17] = '~';
    map [12][18] = '~';
    map [12][19] = '~';
    for (int i=20; i<30;i++){
        map[12][i] = '.';
    }

    for (int i=0; i<5; i++){
        map[13][i] = '^';
    }
    map [13][5] = '*';
    map [13][6] = '*';
    map [13][7] = '*';
    map [13][8] = '*';
    map [13][9] = '*';
    map [13][10] = '*';
    map [13][11] = '*';
    map [13][12] = '*';
    map [13][13] = '*';
    map [13][14] = '*';
    map [13][15] = '*';
    map [13][16] = '~';
    map [13][17] = '~';
    map [13][18] = '~';
    map [13][19] = '~';
    for (int i=20; i<30;i++){
        map[13][i] = '.';
    }

    for (int i=0; i<4; i++){
        map[14][i] = '^';
    }
    map [14][4] = '*';
    map [14][5] = '*';
    map [14][6] = '*';
    map [14][7] = '*';
    map [14][8] = '*';
    map [14][9] = '*';
    map [14][10] = '*';
    map [14][11] = '*';
    map [14][12] = '*';
    map [14][13] = '*';
    map [14][14] = '*';
    map [14][15] = '*';
    map [14][16] = '*';
    map [14][17] = '~';
    map [14][18] = '~';
    map [14][19] = '~';
    for (int i=20; i<30;i++){
        map[14][i] = '.';
    }

    map [15][0] = '^';
    map [15][1] = '^';
    map [15][2] = '^';
    for (int i=3; i<17;i++){
        map[15][i] = '*';
    }
    map [15][17] = '|';
    map [15][18] = '|';
    map [15][19] = '|';
    for (int i=20; i<30; i++){
        map[15][i] = '.';
    }

    map [16][0] = '^';
    map [16][1] = '^';
    for (int i=2; i<17;i++){
        map[16][i] = '*';
    }
    map [16][17] = '|';
    map [16][18] = '|';
    map [16][19] = '|';
    for (int i=20; i<30; i++){
        map[16][i] = '.';
    }

    map [17][0] = '^';
    for (int i=1; i<18;i++){
        map[17][i] = '*';
    }
    map [17][18] = '~';
    map [17][19] = '~';
    for (int i=20; i<30; i++){
        map[17][i] = '.';
    }

    map [18][0] = '^';
    for (int i=1; i<18;i++){
        map[18][i] = '*';
    }
    map [18][18] = '~';
    map [18][19] = '~';
    for (int i=20; i<30; i++){
        map[18][i] = '.';
    }

    map [19][0] = '^';
    for (int i=1; i<19;i++){
        map[19][i] = '*';
    }
    map [19][19] = '~';
    map [19][20] = '~';
    for (int i=21; i<30; i++){
        map[19][i] = '.';
    }

    map [19][0] = '^';
    for (int i=1; i<19;i++){
        map[19][i] = '*';
    }
    map [19][19] = '~';
    map [19][20] = '~';
    for (int i=21; i<30; i++){
        map[19][i] = '.';
    }

    map [20][0] = '^';
    for (int i=1; i<19;i++){
        map[20][i] = '*';
    }
    map [20][19] = '~';
    map [20][20] = '~';
    for (int i=21; i<30; i++){
        map[20][i] = '.';
    }

    map [21][0] = '^';
    for (int i=1; i<19;i++){
        map[21][i] = '*';
    }
    map [21][19] = '~';
    map [21][20] = '~';
    for (int i=21; i<30; i++){
        map[21][i] = '.';
    }

    map [22][0] = '^';
    for (int i=1; i<20;i++){
        map[22][i] = '*';
    }
    map [22][20] = '~';
    for (int i=21; i<30; i++){
        map[22][i] = '.';
    }

    map [23][0] = '^';
    for (int i=1; i<20;i++){
        map[23][i] = '*';
    }
    map [23][20] = '~';
    for (int i=21; i<30; i++){
        map[23][i] = '.';
    }

    map [24][0] = '^';
    for (int i=1; i<20;i++){
        map[24][i] = '*';
    }
    map [24][20] = '~';
    for (int i=21; i<30; i++){
        map[24][i] = '.';
    }

    map [25][0] = '^';
    map [25][1] = '^';
    for (int i=2; i<20;i++){
        map[25][i] = '*';
    }
    map [25][20] = '~';
    for (int i=21; i<30; i++){
        map[25][i] = '.';
    }

    map [26][0] = '^';
    map [26][1] = '^';
    map [26][2] = '^';
    map [26][3] = '^';
    for (int i=4; i<20;i++){
        map[26][i] = '*';
    }
    map [26][20] = '~';
    for (int i=21; i<30; i++){
        map[26][i] = '.';
    }

    map [27][0] = '^';
    map [27][1] = '^';
    map [27][2] = '^';
    map [27][3] = '^';
    map [27][4] = '^';
    for (int i=5; i<20;i++){
        map[27][i] = '*';
    }
    map [27][20] = '~';
    for (int i=21; i<30; i++){
        map[27][i] = '.';
    }

    map [28][0] = '^';
    map [28][1] = '^';
    map [28][2] = '^';
    map [28][3] = '^';
    map [28][4] = '^';
    for (int i=5; i<20;i++){
        map[28][i] = '*';
    }
    map [28][20] = '~';
    for (int i=21; i<30; i++){
        map[28][i] = '.';
    }

    for (int i=0;i<30;i++){
        map[29][i] = '^';
    }
    return;
}
