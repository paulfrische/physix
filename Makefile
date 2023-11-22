SRC = $(wildcard src/*.cpp)

all:
	mkdir -p out
	clang++ -o out/game -std=c++20 -g $(SRC) -lraylib

clean:
	rm -rdf out

test: all
	./out/game
