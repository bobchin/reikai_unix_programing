CC=gcc
CFLAGS=

all: clear

clear:
	rm -rf exam5-5 exam5-6 exam5-7 exam5-8 exam5-10\
	       prac5-7 prac5-8

exam5-5: exam5-5.c
	$(CC) $(CFLAGS) $@.c -o $@

exam5-6: exam5-6.c ../sub/mysub.c
	$(CC) $(CFLAGS) $@.c ../sub/mysub.c -o $@

exam5-7: exam5-7.c ../sub/mysub.c
	$(CC) $(CFLAGS) $@.c ../sub/mysub.c -o $@

exam5-8: exam5-8.c ../sub/mysub.c
	$(CC) $(CFLAGS) $@.c ../sub/mysub.c -o $@

exam5-10: exam5-10.c ../sub/mysub.c ../sub/myvec.c
	$(CC) $(CFLAGS) $@.c ../sub/mysub.c ../sub/myvec.c -o $@

prac5-7: prac5-7.c
	$(CC) $(CFLAGS) $@.c -o $@

prac5-8: prac5-8.c
	$(CC) $(CFLAGS) $@.c -o $@
