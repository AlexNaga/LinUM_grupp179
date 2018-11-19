CC = gcc

LIBFLAG = -L. -lcomponent -Wl,-rpath,.

all:	program

program:	main.c libcomponent.so
		$(CC) -Wall -o program main.c $(LIBFLAG) -lm

libcomponent.so:	libcomponent.c libcomponent.h
		$(CC) -c -fPIC libcomponent.c
		$(CC) -shared -fPIC -o libcomponent.so libcomponent.o
		
