PROGNAME = tc
CC = gcc
CFLAGS = -Wall -g
ifeq ($(BUILD),debug)
	CFLAGS += -O0 -g
else
	CFLAGS += -O2 -s -DNDEBUG
endif 
LFLAGS = 
OBJS = main.o renderer.o mem.o

all: $(PROGNAME)

debug:
	make "BUILD=debug"

$(PROGNAME):	$(OBJS)
		$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $(PROGNAME)

main.o:   main.c
	$(CC) $(CFLAGS) -c main.c

renderer.o:   renderer.c
	$(CC) $(CFLAGS) -c renderer.c

mem.o:   mem.c
	$(CC) $(CFLAGS) -c mem.c

clean:
		rm -f $(OBJS) $(PROGNAME)
