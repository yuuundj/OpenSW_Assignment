PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib
LIBS=$(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a
CC=gcc

.PHONY: all basic_ops advanced_ops clean

all: basic_ops advanced_ops $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(OBJ_DIR)/myapp.o $(LIBS)
	$(CC) -o $@ $(OBJ_DIR)/myapp.o -L$(LIB_DIR) -lmyadvanced -lmybasic -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops:
	$(MAKE) -C advanced_ops

clean:
	rm -rf $(OBJ_DIR)/*.o $(LIB_DIR)/* $(BIN_DIR)/*
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean