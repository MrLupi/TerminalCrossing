PROG = tc
CC = gcc
CFLAGS = -g
OBJ = main.o renderer.o
    
%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
$(PROG):	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	
