# Common flags
LDFLAGS_COMMON = -lGLEW -lGL -lGLU -lglut -lstdc++
CFLAGS_COMMON  = -c -Wall -I./ -O3 -DGL_SILENCE_DEPRECATION

# Compiler
CC      = g++
CFLAGS  = ${CFLAGS_COMMON}
LDFLAGS = ${LDFLAGS_COMMON}

# Executable names
LINREG_EXE   = ./bin/linReg
# LOGREG_EXE   = ./bin/logReg
EXECUTABLES  = $(LINREG_EXE) $(LOGREG_EXE)

# Source files
LINREG_SOURCES = main.cpp

OBJECTS = $(LINREG_SOURCES:.cpp=.o)

# Default target
all: $(EXECUTABLES)

# Build rules
$(LINREG_EXE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

# $(EXECUTABLE_3): $(OBJECTS_3D)
# 	$(CC) $(OBJECTS_3D) $(LDFLAGS) -o $@

# Generic rule for .cpp -> .o
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# Clean rule
clean:
	rm -f *.o $(EXECUTABLES)