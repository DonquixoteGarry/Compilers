.PHONY: all clean main run 0 1
all: 1 clean
main.tab.cc: main.y
	bison -o main.tab.cc -v main.y
lex.yy.cc: main.l
	flex -o lex.yy.cc main.l
main:
	g++ $(shell ls *.cpp *.cc) -o main.out
run: lex.yy.cc main.tab.cc main
clean:
	rm -f *.output *.yy.* *.tab.* test/*.out test/*.s
0:run
	./main.out <test/0.c >test/0.s
	rm -f *.output *.yy.* *.tab.* *.out
	gcc test/0.s -m32 -o test/0.out
1:0
	qemu-i386 test/0.out