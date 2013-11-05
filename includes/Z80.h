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

	public:
		uint32_t cycles;
		//8-bit regesters
		
		uint8_t a; //GP
		uint8_t b; //GP
		uint8_t c; //GP
		uint8_t d; //GP
		uint8_t e; //GP
		uint8_t h; //GP
		uint8_t l; //GP
		uint8_t f; //FLAGS
		uint8_t int_stat;
		uint8_t I;
		uint8_t R;
		//16-bit registers
		uint16_t pc; //Program Counter
		uint16_t sp; //Stack Pointer
		uint16_t IX;
		uint16_t IY;
		
		uint16_t afa;
		uint16_t bca;
		uint16_t dea;
		uint16_t hla;
		//Functions
		void step();
		void reset();
		void processOpcode(uint8_t opcode);
		Z80Cpu();
		bool running;
		Z80Memory memory;
};

#endif
