.PHONY: clean

COMPILE_FLAGS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors -std=c++20
LINK_FLAG = 

rpg.exe: main.obj intro.obj player.obj playerChoiceCatalogue.obj settings.obj
	$(CXX) -o $@ $^ $(LINK_FLAGS)

main.obj: main.cpp intro.hpp player.hpp playerChoiceCatalogue.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

intro.obj: intro.cpp intro.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

player.obj: player.cpp player.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

playerChoiceCatalogue.obj: playerChoiceCatalogue.cpp playerChoiceCatalogue.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

settings.obj: settings.cpp settings.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)