main.o: main.cpp main.h
	g++ -c main.cpp

print_menu.o: print_menu.cpp main.h
	g++ -c print_menu.cpp

print_map.o: print_map.cpp newgame.h
	g++ -c print_map.cpp

newgame.o: newgame.cpp newgame.h monster.h
	g++ -c newgame.cpp

map.o: map.cpp
	g++ -c map.cpp

main: main.o print_menu.o newgame.o print_map.o map.o
	g++ main.o print_menu.o newgame.o print_map.o map.o -lncurses -o main

