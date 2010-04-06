
VPATH := ../bst
VPATH += ../util

CC = gcc
CFLAGS = -Wall -g -std=c99
LFLAGS = -lcunit
IFLAGS  = -I../util -I../bst
TARGETS = bst_test
OBJS = bst_test.o bst.o mpool.o

.c.o:
	$(CC) $(CFLAGS) $(IFLAGS) -c $<

all : $(TARGETS)

bst_test : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS) $(IFLAGS)

check : $(OBJS)
	@./bst_test

clean :
	rm $(TARGETS) $(OBJS) 

bst_test.o: bst_test.c
mpool.o: ../util/mpool.c ../util/mpool.h
bst.o: ../bst/bst.c ../bst/bst.h
