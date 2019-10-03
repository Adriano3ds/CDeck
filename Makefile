all: clean build

run: all
	./build/CDeck

lib_cdeck.o:
	mkdir tmp
	gcc -c CDeck.c -o tmp/lib_cdeck.o

lib: cleanlib cleantmp lib_cdeck.o
	mkdir lib
	ar rcs lib/lib_cdeck.a tmp/lib_cdeck.o
	cp CDeck.h lib/CDeck.h
	rm -rf tmp

build: cleanbuild lib
	mkdir build
	gcc main.c -Llib -l_cdeck -o build/CDeck

cleanbuild:
	rm -rf build

cleanlib: 
	rm -rf lib

cleantmp:
	rm -rf tmp

clean: cleanbuild cleanlib cleantmp
