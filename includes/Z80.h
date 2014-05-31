#ifndef Z80_CPU_H
#define Z80_CPU_H
#include <string>
#include <stdint.h>
#include <GenericCpu.h>
#include <Z80.h>
#include <Z80Memory.h>
using namespace std;
class Z80Cpu: public GenericCpu {
	private:
		//Internal Functions
		void debugOpcode(string name, uint8_t opcode);
		void debugOpcode8(string name,uint8_t operand, uint8_t opcode);
		void debugOpcode16(string name,uint16_t operand, uint8_t opcode);
	public:
		uint32_t cycles;
		//8-bit regesters
		
		uint8_t a; //GP
		uint8_t b; //GP
		uint8_t c; //GP
		uint8_t d; //GP
		uint8_t e; //GP
		uint16_t hl; //GP
		uint8_t int_stat;
		uint8_t I;
		uint8_t R;
		//16-bit registers
		uint16_t pc; //Program Counter
		uint16_t sp; //Stack Pointer
		uint16_t IX;
		uint16_t IY;
		
		bool flag_sign,flag_zero,flag_interrupt,flag_adjust,flag_parity,flag_carry; // S Z I H P C
		//Functions
		void step();
		void reset();
		void processOpcode(uint8_t opcode);

		void push8(uint8_t value);
		void push16(uint16_t value);
		uint16_t pop16();
		uint8_t pop8();
		Z80Cpu();
		bool running;
		Z80Memory memory;
};

#endif
