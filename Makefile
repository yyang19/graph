# Makefile template for shared library

LIB_NAME=graph
DIST=debug
#  
#  CC = gcc # C compiler

ifeq ($(strip $(DIST)),debug)
	CFLAGS = -fPIC -Wall -Wextra -pg -g # C flags
else
	CFLAGS = -fPIC -Wall -Wextra -O2  # C flags
endif

#LDFLAGS = -shared  # linking flags
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command
#TARGET_LIB = libgraph.so # target lib
TARGET_LIB = lib${LIB_NAME}.so # target lib

BASE_PATH=.
BASE_LIB_PATH=$(BASE_PATH)/lib
BASE_HEADER_PATH=./
TARGET_LIB_PATH=$(BASE_PATH)/lib

SRCS = fifo.c bfs.c dfs.c# source files
OBJS = $(SRCS:.c=.o)

CFLAGS += -I${BASE_HEADER_PATH}
LDFLAGS += -L${BASE_LIB_PATH}
	 
.PHONY: all
all: ${TARGET_LIB}
	 
$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^
		 
$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@
			 
include $(SRCS:.c=.d)
	 
.PHONY: clean install
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)

install:
	cp ${TARGET_LIB} ${TARGET_LIB_PATH}
