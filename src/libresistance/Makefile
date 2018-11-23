# Makefile for libresistance. all builds the testprogram
# lib builds the library.

all:	resistanceTest

resistanceTest:	resistance.o main.o
	gcc -o resistanceTest resistance.o main.o

resistance.o:	libresistance.c libresistance.h
	gcc -c libresistance.c -o resistance.o

main.o:	main.c 
	gcc -c main.c

libresistance.o:	libresistance.c libresistance.h
	gcc -c -fPIC libresistance.c -o libresistance.o

lib:	libresistance.o
	gcc libresistance.o -shared -o libresistance.so

