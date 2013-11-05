# Ymgyrch Build Script

AS := nasm
CC := gcc
CPP := g++
ASFLAGS :=
LD := g++
LFLAGS :=
CPPFLAGS := -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith \
-Wmissing-declarations -Winline -Wundef -Wcast-qual -Wshadow -Wwrite-strings \
-Wno-unused-parameter -Wfloat-equal -ansi

#Files
#Format: {NAME}_{TYPE} := $(patsubst %.cpp,%.o,$(wildcard {PATH}/*.cpp))
COREFILES_CPP := $(patsubst %.cpp,%.o,$(wildcard core/*.cpp))
#Bytecode
YBF_CPP := $(patsubst %.cpp,%.o,$(wildcard bytecode/ybf/*.cpp))
SMTL_CPP:= $(patsubst %.cpp,%.o,$(wildcard bytecode/smtl/*.cpp))
#CPU
8086_CPP:= $(patsubst %.cpp,%.o,$(wildcard cpu/8086*.cpp))
LR35902_CPP:= $(patsubst %.cpp,%.o,$(wildcard cpu/LR35902*.cpp))
#----------
.PHONY: all clean

all: clean gameboy core run

core: ${COREFILES_CPP}
	@echo "Building Core"
	@${LD} -o ymgyrch ${COREFILES_CPP} ${LR35902_CPP}

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
	@rm -R -f ./cpu/*.o
	@rm -R -f ./bytecode/ybf/*.o
	@rm -R -f ./bytecode/smtl/*.o
	@rm -R -f ./ymgyrch

clean-docs:
	-@rm -f -r ./docs/
run: 
	@./ymgyrch


8086: ${8086_CPP}
	@echo "Added CPU: 8086"
ybf: ${YBF_CPP}
	@echo "Added YBF"
smtl: ${SMTL_CPP}
	@echo "Added SMTL"
lr35902: ${LR35902_CPP}
	@echo "Added CPU: LR35902"

#Systems
gameboy: lr35902
	@echo "Added System: Gameboy"