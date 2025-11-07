PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
INC_DIR=../include
LIB_DIR=../lib
SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))
CC=gcc
AR=ar

.PHONY: all clean

all: $(LIB_DIR)/libmyadvanced.a

$(LIB_DIR)/libmyadvanced.a: $(OBJS)
	$(AR) rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -rf $(OBJS)