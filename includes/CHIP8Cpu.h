#ifndef CHIP8_CPU_H
#define CHIP8_CPU_H
#include <string>
#include <stdint.h>
#include <LR35902.h>
#include <LR35902Memory.h>
#include <GenericCpu.h>
using namespace std;
class CHIP8Cpu: public GenericCpu {
	private:
		//Internal Functions
		void debugOpcode(string name, uint8_t opcode);
		void renderScreen();
		unsigned char gfx[64 * 32];
		unsigned short stack[16];
		unsigned short sp;
		unsigned char memory[4096];
		unsigned char V[16];
		unsigned short I;
		unsigned short pc;
		unsigned char delay_timer;
		unsigned char sound_timer;
	public:
		
		//Functions
		void step();
		void reset();
		void processOpcode(uint8_t opcode);
		CHIP8Cpu();
		bool running;
		unsigned char mem_readchar(unsigned short location);
		void mem_writechar(unsigned short location,unsigned char data);
};

#endif
