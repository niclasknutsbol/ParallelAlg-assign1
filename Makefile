OBJS = sieve.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall libmcbsp1.2.0.a $(DEBUG)

seq_sieve : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o seq_sieve

clean:
	\rm *.o seq_sieve
