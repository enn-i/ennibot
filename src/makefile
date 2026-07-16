# This makefile assumes the correct setup of the environment. To use this repository check out concord, a discord API translation for C.
TOP = ..

CORE_DIR      = $(TOP)/core
INCLUDE_DIR   = $(TOP)/include
GENERATED_DIR = $(TOP)/generated

CFLAGS  += -O0 -g -pthread -Wall \
           -I$(INCLUDE_DIR) -I$(CORE_DIR) -I$(GENERATED_DIR) \
           -I$(TOP)/reflect-c
LDFLAGS  = -L$(TOP)/lib
LDLIBS   = -ldiscord -lcurl

botname = ennibot
links = utils_ennibot.o ennibot.o wrappers.o embeds.o
compiles = utils_ennibot.c ennibot.c wrappers.c embeds.c
H_FILES = utils_ennibot.h wrappers.h embeds.h

default: $(botname)

$(botname) : $(links) $(H_FILES)
	gcc $(CFLAGS) $(links) -o $(botname) $(LDFLAGS) $(LDLIBS)
	./$(botname)

$(links) : $(compiles) $(H_FILES)
	gcc $(CFLAGS) -c $(compiles) 


clean: 
	rm -rf $(links) $(butname)

.PHONY: default clean

