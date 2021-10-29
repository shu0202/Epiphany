# comp2113
## Team members
### Team member 1
### shu0202:
### Name: Yeung Yan Chun
### UID: 3035707255
### Team member 2
### Name: Chang Ching Yin
### UID: 3035705453
## Game Name: Epiphany
### Introduction:
This game is a single player role-playing game inspired by the 2015 game 'Undertale'. The game sets out at a mysterious forest where the protagonist found himself waking up in. At first glance, Epiphany may appear to be the same as any other ordinary rpg games. But soon the player will notice some twists about it...

Game rule: There two maps signify two stages of the game. At each map, the player has to reach a certain point for a boss encounter by moving up, down, left, right. On his way, there are random monster encounters. The player can enter the 2nd stage only when he has done a boss encounter at the 1st stage. The starting points in the two maps represent game checkpoints. If the player's hp goes down to zero at any point of the game, he is respawn at the latest checkpoint. The goal of the player is to get to the final boss encounter in the second map. 

### Features:
There will be a main menu where the player can choose game modes (start, continue, etc.) When the game starts the player can type their name and they will use this name throughout the gaming process. There are two maps that the users can explore. When the user is walking in the map, there are predefined chances for player to encounter a monster. A combat system will be implemented during the encounter. The game will feature some player status (Hp, atk, etc.) just like other RPG games. After the encounter the data of the monsters will be erased if the monster is killed. The player can quit the game anytime by choosing save in the option menu. 

### Coding requiements:
1. Generation of random game sets or events
   - The player has a probability to obtain random drop (equipments: e.g. armour, weapon) from killing opponents.
   - The player will have random encounters when moving in the map
   - The oponent is randomly seleted from a list of monsters.
   - During combat, both the player and monsters has a deafult 5% critical chance to deal 30% more damage. Such chance for the player can be affected by current equipments.
2. Data structures for storing game status
   - The Hp of the player is stored in an integer variable called Hp.
   - The attack damage that the player can be dealt is stored in an integer variable called atk.
   - The crit chance of the player can be stored in an integer variable called crit.
   - The name of the player is stored in a string variable called name.
   - Each monster will have a set of unique status (hp, atk, etc) and it is stored individually and can be erased.
3. Dynamic memory management
   - After each encounter, the data of the opponents is erased from the program to confine memory usage.
4. File input/output (e.g., for loading/saving game status)
   - The files are saved by a text file. The text file contains below:
   - No. of map the player is in.
   - Hp of player, Atk of player etc..
   - No. of monsters remain.
   - The position where the player is at. 
5. Program codes in multiple files
   - Program codes for main menu (game lobby), off-battle (walking in the map) and in-battle (monster encounter) 
     are separated in different files.

