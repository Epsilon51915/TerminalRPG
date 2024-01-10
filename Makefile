.PHONY: clean

# Note: The officially supported build system for Windows
# is MVSC/Visual Studio.
ifeq ($(OS), Windows_NT)
EXECUTABLE_NAME = rpg.exe
else
EXECUTABLE_NAME = rpg
endif
COMPILE_FLAGS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors -std=c++20
LINK_FLAGS =
EXE_DIR = bin
OBJ_DIR = obj

release: $(EXE_DIR)/$(EXECUTABLE_NAME)
$(EXE_DIR)/$(EXECUTABLE_NAME): $(OBJ_DIR)/main.obj $(OBJ_DIR)/player.obj $(OBJ_DIR)/inventory.obj $(OBJ_DIR)/enemy.obj $(OBJ_DIR)/game.obj
	mkdir -p $(EXE_DIR)
	$(CXX) -o $@ $^ $(LINK_FLAGS)

$(OBJ_DIR)/main.obj: main.cpp game.hpp
	mkdir -p $(OBJ_DIR)
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

$(OBJ_DIR)/player.obj: player.cpp player.hpp inventory.hpp enemy.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

$(OBJ_DIR)/inventory.obj: inventory.cpp inventory.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

$(OBJ_DIR)/enemy.obj: enemy.cpp enemy.hpp
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

$(OBJ_DIR)/game.obj: game.cpp game.hpp player.hpp inventory.hpp enemy.hpp
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
	rm -f $(EXE_DIR) $(OBJ_DIR)
