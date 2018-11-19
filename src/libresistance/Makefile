# Makefile for libresistance. all builds the testprogram
# lib builds the library.

all:	resistanceTest

resistanceTest:	resistance.o main.o
	gcc -o resistanceTest resistance.o main.o

resistance.o:	resistance.c resistance.h
	gcc -c resistance.c

main.o:	main.c 
	gcc -c main.c

libresistance.o:	resistance.c resistance.h
	gcc -c -fPIC resistance.c -o libresistance.o

lib:	libresistance.o
	gcc libresistance.o -shared -o libresistance.so

