.PHONY: clean

COMPILE_FLAGS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors -std=c++20
LINK_FLAG = 

rpg.exe: main.obj intro.obj player.obj playerChoiceCatalogue.obj settings.obj sleepFor.obj enemy.obj monsterCatalogue.obj
	$(CXX) -o $@ $^ $(LINK_FLAGS)

main.obj: main.cpp intro.hpp player.hpp playerChoiceCatalogue.hpp sleepFor.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

intro.obj: intro.cpp intro.hpp sleepFor.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

player.obj: player.cpp player.hpp sleepFor.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

playerChoiceCatalogue.obj: playerChoiceCatalogue.cpp playerChoiceCatalogue.hpp sleepFor.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

settings.obj: settings.cpp settings.hpp sleepFor.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

sleepFor.obj: sleepFor.cpp sleepFor.hpp settings.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

enemy.obj:  enemy.cpp enemy.hpp 
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

monsterCatalogue.obj: monsterCatalogue.cpp monsterCatalogue.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)