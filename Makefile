print_menu.o: print_menu.cpp main.h
	g++ -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib -c print_menu.cpp


print_map.o: print_map.cpp newgame.h
	g++ -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib -c print_map.cpp

map.o: map.cpp newgame.h monster.h
	g++ -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib -c map.cpp

print_battle_menu.o: print_battle_menu.cpp newgame.h monster.h print_battle.h
	g++ -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib -c print_battle_menu.cpp

inbattle.o: inbattle.cpp monster.h print_battle.h
	g++ -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib -c inbattle.cpp

savegame.o: savegame.cpp savegame.h monster.h
	g++ -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib -c savegame.cpp

tower.o: tower.cpp tower.h
	g++ -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib -c tower.cpp

loadgame.o: loadgame.cpp loadgame.h monster.h
	g++ -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib -c loadgame.cpp

newgame.o: newgame.cpp newgame.h monster.h inbattle.o print_map.o savegame.h tower.h loadgame.h
	g++ -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib -c newgame.cpp

main.o: main.cpp main.h loadgame.h
	g++ -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib -c main.cpp

main: main.o print_menu.o newgame.o print_map.o map.o print_battle_menu.o inbattle.o savegame.o tower.o loadgame.o
	g++ -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib main.o print_menu.o newgame.o print_map.o map.o print_battle_menu.o inbattle.o savegame.o tower.o loadgame.o -lncursestw -ldl -pthread -o main

