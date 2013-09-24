# Ymgyrch Build Script
AS := nasm
CC := gcc
CPP := g++
ASFLAGS :=
LD := g++
LFLAGS :=
CFLAGS := -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith \
-Wmissing-declarations -Winline -Wundef -Wcast-qual -Wshadow -Wwrite-strings \
-Wno-unused-parameter -Wfloat-equal -pedantic -ansi
CPPFLAGS := $(CFLAGS)
COREFILES_CPP := $(patsubst %.cpp,%.o,$(wildcard core/*.cpp)) $(patsubst %.cpp,%.o,$(wildcard bytecode/ybf/*.cpp))
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
	@rm -R -f ./bytecode/ybf/*.o
	@rm -R -f ./ymgyrch

clean-docs:
	-@rm -f -r ./docs/
arch:
	@echo "Making for ${ARCH}"
