
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
CPPFLAGS := 
COREFILES_CPP := $(patsubst %.cpp,%.o,$(wildcard core/*.cpp))
YBFFILES_CPP := $(patsubst %.cpp,%.o,$(wildcard bytecode/ybf/*.cpp))
SMTLFILES_CPP:= $(patsubst %.cpp,%.o,$(wildcard bytecode/smtl/*.cpp))

.PHONY: all clean

all: clean ybf smtl core

core: ${COREFILES_CPP}
	@echo "Building Core"
	@${LD} -o ymgyrch ${COREFILES_CPP} ${YBFFILES_CPP} ${SMTLFILES_CPP}

ybf: ${YBFFILES_CPP}
	@echo "Added YBF"

smtl: ${SMTLFILES_CPP}
	@echo "Added SMTL"

%.o: %.cpp
	@echo "Making: " $@
	g++ -c ${CPPFLAGS} -I ./includes/ -o $@ $<

%.o: %.s
	@echo "Making: " $@
	@${AS} ${ASFLAGS} -o $@ $<
clean: clean-docs
	@echo "Cleaning junk..."
	@rm -R -f *.o
	@rm -R -f ./core/*.o
	@rm -R -f ./bytecode/ybf/*.o
	@rm -R -f ./bytecode/smtl/*.o
	@rm -R -f ./ymgyrch

clean-docs:
	-@rm -f -r ./docs/
arch:
	@echo "Making for ${ARCH}"
