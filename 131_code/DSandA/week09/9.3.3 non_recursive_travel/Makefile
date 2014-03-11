TARGET=test

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
%.o: %.c
	$(CC) -g -c $<
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -g -o $@ $(OBJS)
clean:
	rm -rf *.o $(TARGET)
