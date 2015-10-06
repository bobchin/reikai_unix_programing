CC=gcc
CFLAGS=

all: clear

clear:
	rm -rf exam3-1 exam3-2 bye.txt exam3-3 exam3-5 phone1.dat\
	       prac3-1 prac3-2 empty.file prac3-3 prac3-4 output.file

exam3-0:
	od -c hello.txt

exam3-1: exam3-1.c
	$(CC) $(CFLAGS) $@.c -o $@

exam3-2: exam3-2.c
	$(CC) $(CFLAGS) $@.c -o $@

exam3-3: exam3-3.c
	$(CC) $(CFLAGS) $@.c -o $@

exam3-5: exam3-5.c mysub.c
	$(CC) $(CFLAGS) mysub.c $@.c -o $@

prac3-1: prac3-1.c
	$(CC) $(CFLAGS) $@.c -o $@

prac3-2: prac3-2.c
	$(CC) $(CFLAGS) $@.c -o $@

prac3-3: prac3-3.c
	$(CC) $(CFLAGS) $@.c -o $@

prac3-4: prac3-4.c
	$(CC) $(CFLAGS) $@.c -o $@
