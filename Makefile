CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := $(wildcard src/*.cpp src/**/*.cpp src/***/**/*.cpp)
INCLUDE := include

LIBRARIES   := -lGL -lglfw -lGLU -lglut -lm
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)
	$(CXX) $(CXX_FLAGS) -I./$(INCLUDE) $^ $(LIBRARIES) -o $@

clean:
	-rm $(BIN)/*
