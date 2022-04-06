CC = g++
Q = @

CFLAGS = -std=c++14
CFLAGS += -Wall -Wextra -Werror -pedantic
CFLAGS += -m64

SOURCES = $(wildcard src/*.cc)
HEADERS = $(SOURCES:.cc=.h)

PROGRAMS = $(wildcard *.cc)
OBJECTS = $(PROGRAMS:.cc=.o)
TARGETS = $(PROGRAMS:.cc=)

all: $(TARGETS)

$(TARGETS): $(OBJECTS)
	$(Q)$(CC) -o $@ $(CFLAGS) $(@:=.o)
	$(Q)./$@


%.o: %.cc
	$(Q)$(CC) -c -o $@ $(CFLAGS) $<

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(TARGETS)
