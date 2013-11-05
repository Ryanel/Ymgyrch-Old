#ifndef CPU_8086_H
#define CPU_8086_H
#include <string>
#include <stdint.h>
#include <8086Memory.h>
using namespace std;
class I8086Cpu
{
	private:

		//16-bit Registers
		uint16_t ax; //Primary Accumulator
		uint16_t bx; //Base, Accumulator
		uint16_t cx; //Counter, Accumulator
		uint16_t dx; //Accumulator, Misc
		//Index
		uint16_t sp; //Stack Pointer
		uint16_t bp; //Base Pointer
		uint16_t si; //Source Index
		uint16_t di; //Destination Index
		//Segment
		uint16_t cs; //Stack Pointer
		uint16_t ds; //Base Pointer
		uint16_t es; //Source Index
		uint16_t ss; //Stack 
		//Misc
		uint16_t ip; //Program Counter
		uint16_t flags; //Flags (----ODITSZ-A-P-C)
		//Memory
		//uint8_t iomem[65536]; //64 KB of IO Space
		//uint8_t stack[65536]; //64 KB for Stack
	public:
		//Operations
		void step();
		void reset();
		I8086Memory memory;

};

#endif
