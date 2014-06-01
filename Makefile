# Ymgyrch Build Script

AS := nasm
CC := clang -std=c++0x
CPP := clang++
ASFLAGS :=
LD := clang++ -std=c++0x
LFLAGS :=
CPPFLAGS := -g -O2
#Files
#Format: {NAME}_{TYPE} := $(patsubst %.cpp,%.o,$(wildcard {PATH}/*.cpp))
CORE_CPP := $(patsubst %.cpp,%.o,$(wildcard core/*.cpp))
CPU_CPP:= $(patsubst %.cpp,%.o,$(wildcard cpu/*.cpp))
SYSTEM_CPP:= $(patsubst %.cpp,%.o,$(wildcard system/*.cpp))
#----------
.PHONY: all clean ymgyrch

all: cpu system core ymgyrch

clean:
	@echo "Cleaning junk..."
	@rm -R -f *.o
	@rm -R -f ./core/*.o
	@rm -R -f ./cpu/*.o
	@rm -R -f ./system/*.o
	@rm -R -f ./bytecode/ybf/*.o
	@rm -R -f ./bytecode/smtl/*.o
	@rm -R -f ./ymgyrch

core: ${CORE_CPP}
	
ymgyrch:
	@${LD} -o ymgyrch ${CORE_CPP} ${CPU_CPP} ${SYSTEM_CPP}

cpu: ${CPU_CPP}

system: ${SYSTEM_CPP}

%.o: %.cpp
	@echo "Making: " $@
	@${CPP} -c ${CPPFLAGS} -I ./includes/ -o $@ $<

%.o: %.s
	@echo "Making: " $@
	@${AS} ${ASFLAGS} -o $@ $<


clean-docs:
	-@rm -f -r ./docs/
run: 
	@./ymgyrch



