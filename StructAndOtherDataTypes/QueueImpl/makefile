TARGET = queue
OBJS = $(TARGET).o queue_utils.o
DEPS = queue_utils.h makefile

# CFLAGS = -O2
CFLAGS = -O0 -g

%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	gcc -o $@ $^ $(CFLAGS)

.phony: clean
clean: 
	rm -f *.o $(TARGET)