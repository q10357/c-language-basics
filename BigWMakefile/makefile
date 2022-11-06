TARGET = return_pass_struct_functions
OBJS = $(TARGET).o point_utils.o
DEPS = point_utils.h makefile

# CFLAGS = -O2
CFLAGS = -O0 -g

%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	gcc -o $@ $^ $(CFLAGS)

.phony: clean
clean: 
	rm -f *.o $(TARGET)