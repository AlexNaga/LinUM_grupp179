# Makefile for electrotest.
# all compiles the libraries and puts them in the lib directory, and compiles
# the mainprogram with the shared libraries
# lib builds the libraries
# install will give complete file permission to everyone and copy the files
# to /usr/bin and /usr/lib

all:	library electrotest

electrotest: electrotest.o libcomponent.o libresistance.o libpower.o
	gcc -lm electrotest.o -Llib  -lpower -lcomponent -lresistance -o electrotest -Wl,-Rlib

electrotest.o:	electrotest.c libresistance/libresistance.h libpower/libpower.h libcomponent/libcomponent.h
	gcc -lm -c electrotest.c -o electrotest.o
library:	libcomponent.o libresistance.o libpower.o
	mkdir lib
	gcc libresistance.o -shared -o lib/libresistance.so
	gcc libpower.o -shared -o lib/libpower.so
	gcc libcomponent.o -shared -o lib/libcomponent.so

libresistance.o:	libresistance/libresistance.c libresistance/libresistance.h
	gcc -c -fpic libresistance/libresistance.c -o libresistance.o

libpower.o:	libpower/libpower.c libpower/libpower.h
	gcc -c -fpic -lm libpower/libpower.c -o libpower.o

libcomponent.o:	libcomponent/libcomponent.c libcomponent/libcomponent.h
	gcc -c -fpic -lm libcomponent/libcomponent.c -o libcomponent.o

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

uninstall:
	rm /usr/lib/libresistance.so /usr/lib/libpower.so /usr/lib/libcomponent.so
	rm /usr/bin/electrotest


