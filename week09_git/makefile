PROJ=$(shell pwd)
SRC=$(PROJ)/src
OBJ=$(PROJ)/obj
LIB=$(PROJ)/lib
INC=$(PROJ)/include
BIN=$(PROJ)/bin

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(subst $(SRC), $(OBJ), $(SRCS:.c=.o))

MYLIB=libmyops.so
CC=gcc

.PHONY: all clean

all: $(BIN)/myapp

$(BIN)/myapp: $(SRC)/myapp.c $(LIB)/$(MYLIB)
	$(CC) -o $@ $(SRC)/myapp.c -L$(LIB) -lmyops -I$(INC)

$(LIB)/$(MYLIB): $(OBJS)
	$(CC) -shared -Wl,-soname=$(MYLIB).1 -o $(LIB)/$(MYLIB).1.0 $^ -lc
	cd $(LIB) && ln -s $(MYLIB).1.0 $(MYLIB).1
	cd $(LIB) && ln -s $(MYLIB).1 $(MYLIB)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -fPIC -c -o $@ $< -I$(INC)

clean:
	rm -rf $(OBJ)/* $(LIB)/* $(BIN)/*