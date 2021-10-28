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
This game is a single player role-playing game inspired by the 2015 game 'Undertale'. The game sets out at a mysterious forest where the protagonist found himself waking up in

At first glance, Epiphany may appear to be the same as any other ordinary rpg games. But soon the player will notice some twists about it...

### Features:

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
3. Dynamic memory management
   - After each encounter, the data of the opponents is erased from the program to confine memory usage.
   - After exiting the map 1, the data of map 1 will be erased and the data of monsters that exists in map 1 will also be erased.
4. File input/output (e.g., for loading/saving game status)
   - The files are saved by a text file. The text file contains below:
     - No. of map the player is in.
     - Hp of player, Atk of player etc..
     - No. of monsters remain.
     - The position where the player is at.
5. Program codes in multiple files
   - Program codes for main menu (game lobby), off-battle (walking in the map) and in-battle (monster encounter) are separated in different files.

