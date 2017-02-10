# GCC
CC       = gcc
LD       = $(CC)
CFLAGS   = -g -O0 -std=c99 -Wall -Wextra -pedantic-errors
#CFLAGS   = -Os -std=c99 -Wall -Wextra -pedantic-errors
CPPFLAGS =
LDFLAGS  =
#LDFLAGS  = -static -s -lSDL

BIN = colorflood
OBJS = util.o board.o colorflood.o

all: options $(BIN)

options:
	@echo $(BIN) build options:
	@echo "CC       = $(CC)"
	@echo "LD       = $(LD)"
	@echo "CFLAGS   = $(CFLAGS)"
	@echo "CPPFLAGS = $(CPPFLAGS)"
	@echo "LDFLAGS  = $(LDFLAGS)"

$(BIN): $(OBJS)
	@echo LD $@
	@$(LD) $(LDFLAGS) -o $@ $^

.c.o:
	@echo CC $<
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@echo cleaning
	@rm -f $(BIN) $(OBJS)

.PHONY: options clean
