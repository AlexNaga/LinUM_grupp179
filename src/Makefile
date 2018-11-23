# Makefile for electrotest.
# all compiles the libraries and puts them in the lib directory, and compiles
# the mainprogram with the shared libraries
# lib builds the libraries
# install will give complete file permission to everyone and copy the files
# to /usr/bin and /usr/lib

CC = gcc

all: library electrotest

electrotest: electrotest.o libcomponent.o libresistance.o libpower.o
	$(CC) electrotest.o -Llib -lpower -lcomponent -lresistance -o electrotest -Wl,-Rlib -lm

electrotest.o: electrotest.c libresistance/libresistance.h libpower/libpower.h libcomponent/libcomponent.h
	$(CC) -c electrotest.c -o electrotest.o -lm

library: libcomponent.o libresistance.o libpower.o
	mkdir lib
	$(CC) libresistance.o -shared -o lib/libresistance.so -lm
	$(CC) libpower.o -shared -o lib/libpower.so -lm
	$(CC) libcomponent.o -shared -o lib/libcomponent.so -lm

libresistance.o: libresistance/libresistance.c libresistance/libresistance.h
	$(CC) -c -fpic libresistance/libresistance.c -o libresistance.o

libpower.o: libpower/libpower.c libpower/libpower.h
	$(CC) -c -fpic libpower/libpower.c -o libpower.o -lm

libcomponent.o:	libcomponent/libcomponent.c libcomponent/libcomponent.h
	$(CC) -c -fpic libcomponent/libcomponent.c -o libcomponent.o -lm

lib: libresistance.o libpower.o libcomponent.o
	$(CC) libresistance.o -shared -o libresistance.so -lm
	$(CC) libpower.o -shared -o libpower.so -lm
	$(CC) libcomponent.o -shared -o libcomponent.so -lm

install: lib electrotest.o
	install libresistance.so libpower.so libcomponent.so /usr/lib
	$(CC) electrotest.o -L/usr/lib -lpower -lcomponent -lresistance -o electrotest -Wl,-R/usr/lib
	install electrotest /usr/bin

clean:
	rm -rf *.o *.so

uninstall:
	rm /usr/lib/libresistance.so /usr/lib/libpower.so /usr/lib/libcomponent.so
	rm /usr/bin/electrotest