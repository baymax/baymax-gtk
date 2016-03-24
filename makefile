
CC = g++


LIBS = `pkg-config --libs gtk+-3.0` -std=c++11

CFLAGS = `pkg-config --cflags gtk+-3.0` -std=c++11 -Iheader/
LDFLAGS = `pkg-config --libs gtk+-3.0` -pthread

HEADER_DIR = header/
SRC_DIR = src/
OBJ_DIR = obj/
BIN_DIR = executable/

HEADER_FILES = $(HEADER_DIR)*.h
SOURCE_FILES = $(SRC_DIR)*.cpp
OBJ_FILES = $(OBJ_DIR)*.o

EXECUTABLE = baymax-gtk

ALL: $(EXECUTABLE)

#$(OBJ_DIR)fan.o: $(SRC_DIR)fan.c $(HEADER_DIR)fan.h
#	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)cmdparser.o: $(SRC_DIR)cmdparser.cpp $(HEADER_DIR)cmdparser.h
	$(CC) -c -o $@ $< $(CFLAGS)


$(OBJ_DIR)pipeline.o: $(SRC_DIR)pipeline.cpp $(HEADER_DIR)pipeline.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)functions.o: $(SRC_DIR)functions.cpp $(HEADER_DIR)functions.h $(OBJ_DIR)pipeline.o
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJ_DIR)uifunctionality.o: $(SRC_DIR)uifunctionality.cpp $(HEADER_DIR)uifunctionality.h $(OBJ_DIR)functions.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)init.o: $(SRC_DIR)init.cpp $(HEADER_DIR)init.h $(OBJ_DIR)init.o $(OBJ_DIR)uifunctionality.o $(OBJ_DIR)pipeline.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)main.o: $(SRC_DIR)main.cpp $(HEADER_DIR)main.h $(OBJ_DIR)init.o $(OBJ_DIR)cmdparser.o #$(OBJ_DIR)fan.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ_DIR)main.o
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o executable/$(EXECUTABLE)
	
clean:
	rm $(OBJ_FILES)

run:
	./executable/$(EXECUTABLE)

debug: $(EXECUTABLE) run

install: $(EXECUTABLE)
	cp -R ui /usr/share/baymax/ui/
	cp $(BIN_DIR)$(EXECUTABLE) /bin/$(EXECUTABLE)
	chmod +x /bin/$(EXECUTABLE)