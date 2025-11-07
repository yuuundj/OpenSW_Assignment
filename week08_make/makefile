PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib

CC=gcc
AR=ar

.PHONY: all basic clean

all: $(BIN_DIR)/myapp

basic: $(LIB_DIR)/libmybasic.a

$(BIN_DIR)/myapp: $(LIB_DIR)/libmybasic.a $(OBJ_DIR)/myapp.o
	$(CC) -o $@ $(OBJ_DIR)/myapp.o -lmybasic -L$(LIB_DIR)

$(LIB_DIR)/libmybasic.a: $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o
	$(AR) rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)/*.o $(LIB_DIR)/* $(BIN_DIR)/*