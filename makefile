# Common flags
LDFLAGS_COMMON = -lGLEW -lGL -lGLU -lglut -lstdc++
CFLAGS_COMMON  = -c -Wall -I./ -I./imgui -I./imgui/backends -O3 -DGL_SILENCE_DEPRECATION

# Compiler
CC      = g++
CFLAGS  = ${CFLAGS_COMMON}
LDFLAGS = ${LDFLAGS_COMMON}

# Executable names
EXECUTABLE   = ./bin/cppredict

# Source files
SOURCES = \
  main.cpp \
  imgui/imgui.cpp \
  imgui/imgui_draw.cpp \
  imgui/imgui_tables.cpp \
  imgui/imgui_widgets.cpp \
  imgui/imgui_demo.cpp \
  imgui/backends/imgui_impl_opengl3.cpp \
  imgui/backends/imgui_impl_glut.cpp

OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(EXECUTABLE)

# Build rules
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# Clean rule
clean:
	rm -f *.o $(EXECUTABLE)
