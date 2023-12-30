.PHONY: clean

COMPILE_FLAGS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors -std=c++20
LINK_FLAG = 

rpg.exe: main.obj player.obj inventory.obj enemy.obj game.obj
	$(CXX) -o $@ $^ $(LINK_FLAGS)

main.obj: main.cpp game.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

player.obj: player.cpp player.hpp inventory.hpp enemy.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

inventory.obj: inventory.cpp inventory.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

enemy.obj: enemy.cpp enemy.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

game.obj: game.cpp game.hpp player.hpp inventory.hpp enemy.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)
