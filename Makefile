# SDL2
SDL_LIB=-L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib -lSDL2_image -lSDL2_ttf
SDL_INCLUDE=-I/usr/local/include

CPP=g++
CPPFLAGS=-Wall -Wextra -pedantic $(SDL_INCLUDE)
LDFLAGS=$(SDL_LIB)

SRC_DIR=src
OBJ_DIR=obj
INCLUDE_DIR=src/include
SRC_FILES=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
HDR_FILES=$(wildcard $(INCLUDE_DIR)/*.h)
BIN=epic_game

all: $(BIN)

$(BIN): $(OBJ_FILES) $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) $(OBJ_FILES) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(BIN)
