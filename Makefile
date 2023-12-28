
all: zjc
#	rm -rf zdjk_src/lib
#	cp -r newlib zdjk_src/lib
#	./zjc old
#	gcc -m64 -ggdb -Wall -o djak old.c -lX11 -lGL -lGLU 
	./zjc src
	gcc -m64 -ggdb -Wall -o dj src.jack.c -lX11 -lGL -lGLU 
	./dj src

grind:
	scc -c src.jack.c
	ld -Map=map src.jack.o /u/scc/lib/libscc.a /u/scc/lib/crt0.o
	rm -f callgrind.out.*
	#cc src.jack.c
	valgrind --tool=callgrind ./a.out t1
	kcachegrind callgrind.out.*

zjc: zjc.c
	gcc -m64 -ggdb -Wall -o zjc zjc.c -lX11 -lGL -lGLU 

mac:
#	scp jml@192.168.43.93:src/jack/jackc.c .
	xcodebuild

win:
	rm -rf jackc/lib
	cp -r lib jackc/
	./jack.run jackc
	i686-w64-mingw32-gcc -g -municode  jackc.c -lgdi32 -lwsock32 -lopengl32 -lwinspool -lshell32 -luuid -o jack32.exe 
	x86_64-w64-mingw32-gcc -g -municode  jackc.c -lgdi32 -lwsock32 -lopengl32 -lwinspool -lshell32 -luuid -o jack64.exe 


test:
	rm -rf tests/lib
	cp -r newlib tests/lib
	./zdjk tests
	cc -g tests.c -o tests.run -lX11 -lGL -lGLU
	./tests.run
	echo done.

install:
	cp jack.run /usr/local/bin
	mkdir -p /usr/local/share/jack/
	cp -r lib/ /usr/local/share/jack/lib/
	echo install done.

distclean: clean
	echo done.

clean:
	rm -f exe.py jackc.py
	rm -f test.txt
	rm -f a.out a.exe hello32.exe
	rm -f ctests/Main.jack.h
	rm -f jackc.c
	rm -f exe/Main.jack.h
	rm -f tests/*.jack.h
	rm -f main_jack.c
	rm -f jack32 jack64 jack32.exe jack64.exe
	rm -f test.xml testo.xml
	rm -f tests.py
	rm -f tests.c
	rm -f zdjk zdjk_src.c djak
	rm -f zjc src.c 
	rm -rf exe/lib
	rm -rf ctests/lib
	rm -rf tests/lib
	rm -rf jackc/lib
	rm -rf zdjk_src/lib
	rm -rf zjc_src/lib
	rm -f *.pyc
	rm -rf __pycache__
	rm -rf hello mkfont
	rm -f hello.run hello.c
	rm -f jack.run tests.run
	rm -rf jack-linux
	rm -f jack-linux.tar.gz
	rm -f dj src.jack.c hello.jack.c zdj hi
	rm -f callgrind.* vgcore.*

hello:
	cc -o jack.run tools/jackc.c -lX11 -lGL -lGLU 
	rm -rf hello/lib
	mkdir -p hello/lib
	cp -r lib/std/ hello/lib/std; cp -r lib/c/ hello/lib/c/ 
	echo 'class Main {' > hello/Main.jack
	echo 'function void main() {' >> hello/Main.jack
	echo 'do Output.printString("Hello World!");' >> hello/Main.jack
	echo 'do Output.println(); return; } }' >> hello/Main.jack
	./jack.run -hack hello
	cc -o hello.run hello.c -lX11 -lGL -lGLU 
	./hello.run

release:
	mkdir -p jack-linux/
	rm -rf jack-linux/*
	cp LICENSE.txt jack-linux/
	cp README.md jack-linux/
	cp jack.run jack-linux/
	tar -cvzf jack-linux.tar.gz jack-linux/

git-release:
	git tag v0.0.0
	git push origin v0.0.0

