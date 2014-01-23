#ifndef YBF_CPU_H
#define YBF_CPU_H
#include <string>
#include <stdint.h>
#include <GenericCpu.h>
#include <ybf/YbfCpu.h>
#include <ybf/YbfMemory.h>
using namespace std;
class YbfCpu: public GenericCpu {
	private:
		//Internal Functions
		void debugOpcode(string name, uint8_t opcode);
		void debugOpcode8(string name,uint8_t operand, uint8_t opcode);
		void debugOpcode16(string name,uint16_t operand, uint8_t opcode);
	public:
		//uint32_t cycles;
		uint8_t R[16]; //General
		//16-bit registers
		uint16_t pc; //Program Counter
		uint8_t XR[16]; //General eXtended Registeres
		uint16_t F; //Flags
		uint16_t I; //Index
		//Functions
		void step();
		void reset();
		void processOpcode(uint8_t opcode);
		YbfCpu();
		bool running;
		YbfMemory memory;
};

#endif
