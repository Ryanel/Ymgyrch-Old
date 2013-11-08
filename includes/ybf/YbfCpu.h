#ifndef Z80_CPU_H
#define Z80_CPU_H
#include <string>
#include <stdint.h>
#include <GenericCpu.h>
#include <ybf/YBFCpu.h>
using namespace std;
class YBFCpu: public GenericCpu {
	private:
		//Internal Functions
		void debugOpcode(string name, uint8_t opcode);
		void debugOpcode8(string name,uint8_t operand, uint8_t opcode);
		void debugOpcode16(string name,uint16_t operand, uint8_t opcode);
	public:
		//uint32_t cycles;
		uint8_t a; //GP
		uint8_t b; //GP
		uint8_t c; //GP
		uint8_t d; //GP
		uint8_t s; //GP
		//16-bit registers
		uint16_t pc; //Program Counter
		uint16_t sp; //Stack Pointer

		bool flag_sign,flag_zero,flag_interrupt,flag_adjust,flag_parity,flag_carry; // S Z I H P C
		//Functions
		void step();
		void reset();
		void processOpcode(uint8_t opcode);
		YBFCpu();
		bool running;
		Z80Memory memory;
};

#endif
