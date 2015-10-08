CC=gcc
CFLAGS=

all: clear

clear:
	rm -rf exam5-5 exam5-6 exam5-7\
	       prac5-7

exam5-5: exam5-5.c
	$(CC) $(CFLAGS) $@.c -o $@

exam5-6: exam5-6.c ../sub/mysub.c
	$(CC) $(CFLAGS) $@.c ../sub/mysub.c -o $@

exam5-7: exam5-7.c ../sub/mysub.c
	$(CC) $(CFLAGS) $@.c ../sub/mysub.c -o $@

prac5-7: prac5-7.c
	$(CC) $(CFLAGS) $@.c -o $@
