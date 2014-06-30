#Para escrever comentários ##
############################# Makefile ##########################
#Definimos a variável
CC=gcc
CFLAGS= -g -Wall `pkg-config --cflags gtk+-2.0` -lmysqlclient 

EXEC=piubol0.40.exe
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)


#all: $(EXEC)

$(EXEC): $(OBJ)
	gcc -o $(EXEC) $(OBJ) ` pkg-config --libs gtk+-2.0` -lmysqlclient
#	make clean 


clean:
	rm  *.o 2>/dev/null || /bin/true 

purge:
	rm  *.exe 2>/dev/null || /bin/true 
	rm  *.o 2>/dev/null || /bin/true 
