# This makefile assumes the correct setup of the environment. To use this repository check out concord, a discord API translation for C.
TOP = ..

CORE_DIR      = $(TOP)/core
INCLUDE_DIR   = $(TOP)/include
GENCODECS_DIR = $(TOP)/gencodecs

CFLAGS  += -O0 -g -pthread -Wall \
           -I$(INCLUDE_DIR) -I$(CORE_DIR) -I$(GENCODECS_DIR)
LDFLAGS  = -L$(TOP)/lib
LDLIBS   = -ldiscord -lcurl

botname = ennibot
links = commands.o ennibot.o
compiles = commands.c ennibot.c
H_FILES = commands.h 

default: $(botname)

$(botname) : $(links) $(H_FILES)
	gcc $(CFLAGS) $(links) -o $(botname) $(LDFLAGS) $(LDLIBS)
	./$(botname)

$(links) : $(links) $(H_FILES)
	gcc $(CFLAGS) -c $(compiles) 


clean: 
	rm -rf $(links) $(butname)

.PHONY: default clean

