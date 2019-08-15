# 简单版本的makefile
# main:file1.o file2.o
# 	g++ file1.o file2.o -o main

# file2.o:file2.cc
# 	g++ -c file2.cc -o file2.o

# file1.o:file1.cc file1.h
# 	g++ -c file1.cc -o file1.o

# clean:
# 	rm -rf *.o main


# 通用版本的makefile

CC = gcc
XX = g++
CFLAGS = -Wall -O -g
TARGET = main

SOURCES = $(wildcard *.c *.cc)
OBJS = $(patsubst %.c,%.o,$(patsubst %.cc,%.o,$(SOURCES)))

$(TARGET):$(OBJS)
	$(XX) $(OBJS) -o $(TARGET)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o:%.cc
	$(XX) $(CFLAGS) -c $< -o $@


# clean:
# 	rm -rf *.o main


# 判断
# if:
# ifeq ($(CC),gcc)
# 	@echo gcc
# else
# 	@echo g++
# endif

# 循环
# LIST = one two three
# all:
# 	@for i in $(LIST); do echo $$i; done
