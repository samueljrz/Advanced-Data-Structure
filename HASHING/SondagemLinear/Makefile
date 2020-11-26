CC=g++
IPATH=-Iinc/
SRC=src/
OBJ=obj/
BIN=bin/
FLAGS=-std=c++14

all: app
	@echo "Sucess"

app: main.o
	@$(CC) $(FLAGS) $(OBJ)* -o $(BIN)app $(FLAGS)
	
main.o:
	@$(CC) $(FLAGS) $(IPATH) -c $(SRC)main.cpp -o $(OBJ)main.o

run:
	@./bin/app

dev: app
	@./bin/app

clean: 
	@rm -rf $(OBJ)*.o $(BIN)*
