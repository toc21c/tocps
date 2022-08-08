TESTS = test \

OBJS = test.o \
	   net.o \
	   loopback.o \

CFLAGS := $(CFLAGS) -g -W -Wall -Wno-unused-parameter -iquote .

.SUFFIXES:
.SUFFIXES: .c .o

.PHONY: all clean

all: $(TESTS)

$(TESTS): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TESTS)
