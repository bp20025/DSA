all: hh

CC = gcc
CFLAGS = -O3 -std=gnu11 -Wall

hh: hh.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

run:
	./hh > hh.dat

clean:
	rm -f hh *.o *~

distclean: clean
	rm -f *.dat
