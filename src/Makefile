# Makefile for electrotest.
# all compiles the libraries and puts them in the lib directory, and compiles
# the mainprogram with the shared libraries
# lib builds the libraries
# install will give complete file permission to everyone and copy the files
# to /usr/bin and /usr/lib

all:	library electrotest

electrotest: electrotest.o libcomponent.o libresistance.o libpower.o
	gcc -lm electrotest.o -Llib  -lpower -lcomponent -lresistance -o electrotest -Wl,-Rlib

library:	libcomponent.o libresistance.o libpower.o
	mkdir lib
	gcc libresistance.o -shared -o lib/libresistance.so
	gcc libpower.o -shared -o lib/libpower.so
	gcc libcomponent.o -shared -o lib/libcomponent.so

libresistance.o:	libresistance.c libresistance.h
	gcc -c -fpic libresistance.c -o libresistance.o

libpower.o:	libpower.c libpower.h
	gcc -c -fpic -lm libpower.c -o libpower.o

libcomponent.o:	libcomponent.c libcomponent.h
	gcc -c -fpic -lm libcomponent.c -o libcomponent.o

lib:	libresistance.o libpower.o libcomponent.o
	gcc libresistance.o -shared -o libresistance.so
	gcc libpower.o -shared -o libpower.so
	gcc libcomponent.o -shared -o libcomponent.so

install:	electrotest.o lib 
	chmod 777 libpower.so libresistance.so libcomponent.so
	cp libresistance.so libpower.so libcomponent.so /usr/lib
	gcc -lm electrotest.o -L/usr/lib -lpower -lcomponent -lresistance -o electrotest -Wl,-R/usr/lib
	chmod 777 electrotest
	cp electrotest /usr/bin
clean:
	rm -f *.o *so


