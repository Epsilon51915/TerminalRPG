.PHONY: clean

EXECUTABLE_NAME = rpg.exe
COMPILE_FLAGS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors -std=c++20
LINK_FLAGS =

release: $(EXECUTABLE_NAME)
$(EXECUTABLE_NAME): main.obj player.obj inventory.obj enemy.obj game.obj
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

ARCHIVE_NAME = TerminalRPG.zip
MSYS_GCC_DLL = msys-gcc_s-seh-1.dll
MSYS_STDCPP_DLL = msys-stdc++-6.dll
MSYS_DLL = msys-2.0.dll

dist: $(ARCHIVE_NAME)
$(ARCHIVE_NAME): $(EXECUTABLE_NAME)
	[[ -f "$(MSYS_GCC_DLL)" ]] || cp "/usr/bin/$(MSYS_GCC_DLL)" ./
	[[ -f "$(MSYS_STDCPP_DLL)" ]] || cp "/usr/bin/$(MSYS_STDCPP_DLL)" ./
	[[ -f "$(MSYS_DLL)" ]] || cp "/usr/bin/$(MSYS_DLL)" ./
	powershell -c "Compress-Archive -Update -Path \"$(EXECUTABLE_NAME)\",\"*.dll\" -DestinationPath \"$(ARCHIVE_NAME)\""

clean:
	rm -f "$(ARCHIVE_NAME)" "$(EXECUTABLE_NAME)" *.obj
