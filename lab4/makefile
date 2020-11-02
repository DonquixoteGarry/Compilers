.PHONY: go,clean
go:
	flex -+ mylexer.l
	g++ lex.yy.cc -o mylexer.out
	./mylexer.out <testin >testout
clean:
	rm lex.yy.cc
	rm mylexer.out