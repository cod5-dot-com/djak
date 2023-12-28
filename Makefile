JACKPATH = .
JACKLIB = \
	$(JACKPATH)/src/array.jack \
	$(JACKPATH)/src/buffer.jack \
	$(JACKPATH)/src/bytes.jack \
	$(JACKPATH)/src/console.jack \
	$(JACKPATH)/src/file.jack \
	$(JACKPATH)/src/hash.jack \
	$(JACKPATH)/src/lang_c.c \
	$(JACKPATH)/src/lang_c.h \
	$(JACKPATH)/src/object.jack \
	$(JACKPATH)/src/worker.jack \
	$(JACKPATH)/src/std.jack \
	$(JACKPATH)/src/string.jack

SRCFILES = \
	src/Aclass.jack \
	src/Aemmiter.jack \
	src/Aemmitc.jack \
	src/Acbody.jack \
	src/Aexpr.jack \
	src/Alexer.jack \
	src/Amember.jack \
	src/Aparser.jack \
	src/Astatement.jack \
	src/Atoken.jack \
	src/Avirtual.jack


all: dj303.run 
	@echo done...

dj303.run: bootstrap.run src/main.jack $(JACKLIB) $(SRCFILES)
	./bootstrap.run dj303 $(JACKLIB) $(SRCFILES) src/main.jack
	cc -ggdb -ansi -Wall -o dj303.run dj303.jack.c -lX11 -lGL -lGLU 


bootstrap.run: tools/bootstrap.c $(JACKLIB) $(SRCFILES)
	cc -ggdb -Wall -o bootstrap0.run tools/bootstrap.c -lX11 -lGL -lGLU 
	./bootstrap0.run bootstrap $(JACKLIB) $(SRCFILES) src/main.jack
	cc -ggdb -Wall -o bootstrap.run bootstrap.jack.c -lX11 -lGL -lGLU 

debug:
	gdb --args \
	./dj303.run gdbtest $(JACKLIB) $(SRCFILES) src/main.jack

leaks:
	valgrind --leak-check=yes \
	./dj303.run leaks $(JACKLIB) $(SRCFILES) src/main.jack


cat.exe:
	./dj303.run cat $(JACKLIB) \
		tools/cat.jack
	cc -ggdb -Wall -o cat.run cat.jack.c -lX11 -lGL -lGLU 

echo.exe:
	./dj303.run echo $(JACKLIB) \
		tools/echo.jack
	cc -ggdb -Wall -o echo.run echo.jack.c -lX11 -lGL -lGLU 

ls.exe:
	valgrind --leak-check=yes \
	./dj303.run ls $(JACKLIB) \
		tools/ls.jack
	cc -ggdb -ansi -Wall -o ls.run ls.jack.c -lX11 -lGL -lGLU 
		
indent:
	tools/indent.sh

grind:
	scc -c src.jack.c
	ld -Map=map src.jack.o /u/scc/lib/libscc.a /u/scc/lib/crt0.o
	rm -f callgrind.out.*
	#cc src.jack.c
	valgrind --tool=callgrind ./a.out t1
	kcachegrind callgrind.out.*

mac:
#	scp jml@192.168.43.93:src/jack/jackc.c .
	xcodebuild

test: dj303.run
	#tests/t_lambda.jack
	./dj303.run test $(JACKLIB) \
		tests/t_async.jack \
		tests/t_switch.jack \
		tests/main.jack
	cc -g test.jack.c -o test.run -lX11 -lGL -lGLU
	gdb -ex run --args ./test.run
	echo test done.

install:
	cp dj303.run /usr/local/bin
	mkdir -p /usr/local/share/djak/
	cp -r lib/ /usr/local/share/djak/lib/
	echo install done.

distclean: clean
	echo done.

clean:
	rm -f *.run
	rm -f *.jack.c
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
	rm -f *.o

git-release:
	git tag v0.0.0
	git push origin v0.0.0

