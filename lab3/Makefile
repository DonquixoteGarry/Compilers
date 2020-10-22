.PHONY : 1,_1,2,_2,3,_3
1:
	bison -d main1.y
	gcc -o main1 main1.tab.c
	./main1
_1:
	rm main1 main1.tab.c main1.tab.h
2:
	bison -d main2.y
	gcc -o main2 main2.tab.c
	./main2
_2:
	rm main2 main2.tab.c main2.tab.h
3:
	bison -d main3.y
	gcc -o main3 main3.tab.c
	./main3
_3:
	rm main3 main3.tab.c main3.tab.h

