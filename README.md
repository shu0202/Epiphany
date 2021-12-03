# comp2113
## Team members
### Team member 1
### shu0202
### Name: Yeung Yan Chun
### UID: 3035707255
### Team member 2
### bohrisc
### Name: Chang Ching Yin
### UID: 3035705453
## Game Name: Epiphany
### Introduction:
This game is a single player role-playing game inspired by the 2015 game 'Undertale'. The game sets out at a mysterious forest where the protagonist found himself waking up in. At first glance, Epiphany may appear to be the same as any other ordinary rpg games. But at the end, the game will check the total number of monsters that you have killed. If it is too high, the player will trigger a bad ending in which the player will face punishment (his family will be killed because of his gruesome and violent act). On the other hand, the player will trigger a good ending for sparing the monsters. The game aims at using this judgement system to educate the player about the consequences of their actions, no matter they are in a game or in real life.

Game rule: There is one map in the game. In the map, the player has to reach the castle in the top left part for a boss encounter by moving up, down, left, right. On his way, there are random monster encounters. If the player's hp goes down to zero at any point of the game, he is respawn at the spawnpoint, the top right corner on the map. The goal of the player is to get to defeat the boss.

### Features:
There will be a main menu where the player can choose game modes (start, continue, etc.) When the game starts the player can type their name and they will use this name throughout the gaming process. There is one 30x30 map that the users can explore. When the user is walking in the map, there are predefined chances for player to encounter a monster. A turn-based combat system will be implemented during the encounter. The game will feature player status (hp, atk, crit_chance) just like other RPG games. After the encounter the data of the monsters will be erased if the monster is killed or spared. The player can save the game data and quit the game anytime when he is no in a battle by pressing p in the keyboard to open the save and exit menu.

### Coding requiements:
1. Generation of random game sets or events
   - The player will have random monster encounters when moving in the map
   - The oponent is randomly seleted from a list of monsters.
   - During combat, both the player and monsters has a deafult 10% critical chance to deal 2 times more damage. Such chance for the player can be affected by current equipments. In addition, both the player and monsters has a 10% chance to miss an attack.
2. Data structures for storing game status
   - The status of the player is stored in a struct called player_stat.
   - The hp of the player is stored in an integer variable called hp in the struct.
   - The attack damage that the player can be dealt is stored in an integer variable called atk in the struct.
   - The crit chance of the player can be stored in an integer variable called crit in the struct.
   - The name of the player is stored in a string array called name in the struct.
   - There is a struct called monster with int variable no, hp and atk. The struct will have two string array called dead and talked which store the text to say when being defeated and talked to respectively. All monster have a default critical chance of 10%.
   - Each monster will have a set of unique status (hp, atk, etc) and it is stored individually and can be erased.
3. Dynamic memory management
   - After each encounter, the data of the opponents is erased from the program to confine memory usage.
4. File input/output (e.g., for loading/saving game status)
   - The game status is saved in a text file. The text file contains below:
   - Name of player, hp of player, atk of player, crit_chance of player.
   - The x and y position where the player is at. 
   - Whether the player has entered the cave before
   - Number of monsters remaining.
   - no (the id) of the reamining monsters. 
   - an alive array that stores the information about the whether the monsters are alive (1) or dead (0).
5. Program codes in multiple files
   - Program codes for main menu (game lobby), off-battle (walking in the map) and in-battle (monster encounter) 
     are separated in different files.

### Non-standard C/C++ libraries:
   - ncurses.h is used in the game for better user experience when playing the game.
   - initscr(), raw(), keypad(), noecho() are for initialization.
   - clear() can be used to clear the screen for more clear visual when playing the game.
   - printw() is like printf() in c to print out game information when playing (e.g. during battle, moving in the map).
   - getch() is used to read a character from the user's keyboard directly and instantly.
   - refresh() is used to refresh the screen.
   - endwin() is used when existing main.cpp, i.e. terminating the game.

### Compilation and execution instructions:
   1. run the command chmod u+x initial.sh in the terminal
   2. run initial.sh in the terminal
      - This allows the relevant functions in the non standard library ncurses.h to be used in the game
   3. make main in the terminal
      - This is to generate the target main
   4. ./main in the terminal and start playing the game.
