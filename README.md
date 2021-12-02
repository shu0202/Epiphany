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
This game is a single player role-playing game inspired by the 2015 game 'Undertale'. The game sets out at a mysterious forest where the protagonist found himself waking up in. At first glance, Epiphany may appear to be the same as any other ordinary rpg games. But soon the player will notice some twists about it...

Game rule: There is one map in the game. In the map, the player has to reach the castle in the top left part for a boss encounter by moving up, down, left, right. On his way, there are random monster encounters. If the player's hp goes down to zero at any point of the game, he is respawn at the spawnpoint, the top right corner on the map. The goal of the player is to get to defeat the boss.

### Features:
There will be a main menu where the player can choose game modes (start, continue, etc.) When the game starts the player can type their name and they will use this name throughout the gaming process. There is one 30x30 map that the users can explore. When the user is walking in the map, there are predefined chances for player to encounter a monster. A turn-based combat system will be implemented during the encounter. The game will feature player status (hp, atk, crit_chance) just like other RPG games. After the encounter the data of the monsters will be erased if the monster is killed or spared. The player can quit the game anytime when he is no in a battle by choosing save in the option menu. 

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
   - ncurses.h is used in the game.
   - 

### Compilation and execution instructions:
   1. run initial.sh in the terminal
      - This allows the relevant functions in the non standard library ncurses.h to be used in the game
   2. make main in the terminal
      - This is to generate the target main
   3. ./main in the terminal and start playing the game.
