print_menu.o: print_menu.cpp main.h
	g++ -c print_menu.cpp


print_map.o: print_map.cpp newgame.h
	g++ -c print_map.cpp

map.o: map.cpp newgame.h monster.h
	g++ -c map.cpp

print_battle_menu.o: print_battle_menu.cpp newgame.h monster.h print_battle.h
	g++ -c print_battle_menu.cpp

inbattle.o: inbattle.cpp monster.h print_battle.h
	g++ -c inbattle.cpp

savegame.o: savegame.cpp savegame.h monster.h
	g++ -c savegame.cpp

newgame.o: newgame.cpp newgame.h monster.h inbattle.o print_map.o savegame.h
	g++ -c newgame.cpp

main.o: main.cpp main.h
	g++ -c main.cpp

main: main.o print_menu.o newgame.o print_map.o map.o print_battle_menu.o inbattle.o savegame.o
	g++ main.o print_menu.o newgame.o print_map.o map.o print_battle_menu.o inbattle.o savegame.o -lncurses -o main

