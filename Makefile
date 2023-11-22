SRC = $(wildcard src/*.cpp)

all:
	mkdir -p out
	clang++ -o out/game $(SRC) -lraylib

clean:
	rm -rdf out

test: all
	./out/game
