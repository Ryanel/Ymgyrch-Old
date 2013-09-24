# Ymgyrch Build Script
AS := nasm
CC := gcc
CPP := g++
ASFLAGS :=
LD := g++
LFLAGS :=
CFLAGS := -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast \
-Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef \
-Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter \
-Wfloat-equal -pedantic -ansi
CPPFLAGS :=
COREFILES_CPP := $(patsubst %.cpp,%.o,$(wildcard core/*.cpp))
.PHONY: all clean

all: clean core

core: ${COREFILES_CPP}
	@echo "Building Core"
	@${LD} -o ymgyrch ${COREFILES_CPP}

%.o: %.cpp
	@echo "Making: " $@
	@g++ -c ${CPPFLAGS} -I ./includes/ -o $@ $<

%.o: %.s
	@echo "Making: " $@
	@${AS} ${ASFLAGS} -o $@ $<
clean: clean-docs
	@echo "Cleaning junk..."
	@rm -R -f *.o
	@rm -R -f ./core/*.o
	@rm -R -f ./ymgyrch

clean-docs:
	-@rm -f -r ./docs/
arch:
	@echo "Making for ${ARCH}"
