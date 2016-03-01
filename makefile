
CC = g++


LIBS = `pkg-config --libs gtk+-3.0` -std=c++11

CFLAGS = `pkg-config --cflags gtk+-3.0` -std=c++11 -Iheader/
LDFLAGS = `pkg-config --libs gtk+-3.0`

HEADER_DIR = header/
SRC_DIR = src/
OBJ_DIR = obj/

HEADER_FILES = $(HEADER_DIR)*.h
SOURCE_FILES = $(SRC_DIR)*.cpp
OBJ_FILES = $(OBJ_DIR)*.o

EXECUTABLE = baymax

ALL: $(EXECUTABLE)

#$(OBJ_DIR)fan.o: $(SRC_DIR)fan.c $(HEADER_DIR)fan.h
#	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)main.o: $(SRC_DIR)main.cpp #$(OBJ_DIR)fan.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ_DIR)main.o
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o executable/$(EXECUTABLE)
    

run:
	./executable/$(EXECUTABLE)

debug: $(EXECUTABLE) run