.PHONY:
	all clean
all:
	bison -o src/parser.cpp -v src/parser.y
	flex -o src/lexer.cpp src/lexer.l
	g++ -o src/main src/lexer.cpp src/parser.cpp src/symbol.cpp src/tree.cpp -std=c++11
clean:
	rm src/main src/parser.cpp src/parser.hpp src/lexer.cpp src/lexer.hpp 
