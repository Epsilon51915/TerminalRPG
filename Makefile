.PHONY: clean

# Note: The officially supported build system for Windows
# is MVSC/Visual Studio.
ifeq ($(OS), Windows_NT)
EXECUTABLE_NAME = rpg.exe
else
EXECUTABLE_NAME = rpg
endif
WARNINGS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors
CXX_VERSION = -std=c++20
OPTIMIZE =
DEBUG =
EXE_DIR = bin
OBJ_DIR = obj
SRC_DIR = .
INCL_DIR = .

release: OPTIMIZE = -O3
release: DEBUG = -DNDEBUG
release: $(EXE_DIR)/$(EXECUTABLE_NAME)

debug: OPTIMIZE = -Og -g
debug: DEBUG = -DDEBUG -D_DEBUG
debug: $(EXE_DIR)/$(EXECUTABLE_NAME)

COMPILE_FLAGS = $(CXX_VERSION) $(WARNINGS) $(OPTIMIZE) $(DEBUG)
LINK_FLAGS =

MAIN_CPP = $(SRC_DIR)/main.cpp
MAIN_OBJ = $(OBJ_DIR)/main.o
PLAYER_CPP = $(SRC_DIR)/player.cpp
PLAYER_HPP = $(INCL_DIR)/player.hpp
PLAYER_OBJ = $(OBJ_DIR)/player.o
INVENTORY_CPP = $(SRC_DIR)/inventory.cpp
INVENTORY_HPP = $(INCL_DIR)/inventory.hpp
INVENTORY_OBJ = $(OBJ_DIR)/inventory.o
ENEMY_CPP = $(SRC_DIR)/enemy.cpp
ENEMY_HPP = $(INCL_DIR)/enemy.hpp
ENEMY_OBJ = $(OBJ_DIR)/enemy.o
GAME_CPP = $(SRC_DIR)/game.cpp
GAME_HPP = $(INCL_DIR)/game.hpp
GAME_OBJ = $(OBJ_DIR)/game.o

$(EXE_DIR)/$(EXECUTABLE_NAME): $(MAIN_OBJ) $(PLAYER_OBJ) $(INVENTORY_OBJ) $(ENEMY_OBJ) $(GAME_OBJ)
	mkdir -p $(EXE_DIR)
	$(CXX) -o $@ $^ $(LINK_FLAGS)

$(MAIN_OBJ): $(MAIN_CPP) $(GAME_HPP)
	mkdir -p $(OBJ_DIR)
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

$(PLAYER_OBJ): $(PLAYER_CPP) $(PLAYER_HPP) $(INVENTORY_HPP) $(ENEMY_HPP)
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

$(INVENTORY_OBJ): $(INVENTORY_CPP) $(INVENTORY_HPP)
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

$(ENEMY_OBJ): $(ENEMY_CPP) $(ENEMY_HPP)
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

$(GAME_OBJ): $(GAME_CPP) $(GAME_HPP) $(PLAYER_HPP) $(INVENTORY_HPP) $(ENEMY_HPP)
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

# We use MSVC for Windows builds now, but I'll
# keep this here for reference.
# > downerj 2024/01/08

#ARCHIVE_NAME = TerminalRPG.zip
#MSYS_GCC_DLL = msys-gcc_s-seh-1.dll
#MSYS_STDCPP_DLL = msys-stdc++-6.dll
#MSYS_DLL = msys-2.0.dll
#dist: $(ARCHIVE_NAME)
#$(ARCHIVE_NAME): $(EXECUTABLE_NAME)
#	[[ -f "$(MSYS_GCC_DLL)" ]] || cp "/usr/bin/$(MSYS_GCC_DLL)" ./
#	[[ -f "$(MSYS_STDCPP_DLL)" ]] || cp "/usr/bin/$(MSYS_STDCPP_DLL)" ./
#	[[ -f "$(MSYS_DLL)" ]] || cp "/usr/bin/$(MSYS_DLL)" ./
#	powershell -c "Compress-Archive -Update -Path \"$(EXECUTABLE_NAME)\",\"*.dll\" -DestinationPath \"$(ARCHIVE_NAME)\""

clean:
	rm -rf $(EXE_DIR) $(OBJ_DIR)
