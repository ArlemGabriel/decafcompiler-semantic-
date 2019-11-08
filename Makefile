
compilador:lex.yy.c parser.tab.c
	g++ parser.tab.c lex.yy.c -o compilador

lex.yy.c:scanner.l parser.tab.c
	flex scanner.l

parser.tab.c:parser.y
	bison -d parser.y

clean:
		rm -f compilador *.o
		rm -f compilador *.c
		rm -f compilador parser.tab.h
		rm -f compilador parser.output
