# Compiler and Flags
CXX = g++
CXXFLAGS = -DGLEW_STATIC -I"$(SDL2_INCLUDE)" -I"$(GLEW_INCLUDE)" -I"imgui" -I"imgui/backends"
LDFLAGS = -L"$(SDL2_LIB)" -L"$(GLEW_LIB)" -lmingw32 -lSDL2main -lSDL2 -lglew32s -lopengl32 -static-libgcc -static-libstdc++

# Directories (update these paths if needed)
SDL2_INCLUDE = C:/Users/ayanh/Downloads/SDL2-devel-2.28.5-mingw/SDL2-2.28.5/x86_64-w64-mingw32/include/SDL2
SDL2_LIB = C:/Users/ayanh/Downloads/SDL2-devel-2.28.5-mingw/SDL2-2.28.5/x86_64-w64-mingw32/lib/x64
SDL2_DLL = C:/Users/ayanh/Downloads/SDL2-devel-2.28.5-mingw/SDL2-2.28.5/x86_64-w64-mingw32/bin/SDL2.dll
GLEW_INCLUDE = C:/Users/ayanh/Downloads/glew-2.1.0-win32/glew-2.1.0new/include
GLEW_LIB = C:/Users/ayanh/Downloads/glew-2.1.0-win32/glew-2.1.0new/lib/Release/x64

# Source Files
SRC = src/main.cpp imgui/imgui.cpp imgui/imgui_draw.cpp imgui/imgui_demo.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/backends/imgui_impl_sdl2.cpp imgui/backends/imgui_impl_opengl3.cpp

# Output file
OUT = build/project.exe

# Default target: build the project
all: $(OUT)

# Rule to build the project
$(OUT): $(SRC)
	mkdir -p build  # Ensure the build folder exists
	g++ $(SRC) -o $(OUT) $(CXXFLAGS) $(LDFLAGS)

# Clean target: remove the build folder
clean:
	rm -rf build/*
