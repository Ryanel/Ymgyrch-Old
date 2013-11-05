#ifndef LR35902_CPU_H
#define LR35902_CPU_H
#include <string>
#include <stdint.h>
#include <LR35902.h>
#include <LR35902Memory.h>
using namespace std;
class LR35902Cpu
{
	private:
		//Internal Functions
		void debugOpcode(string name, uint8_t opcode);


	public:
		//8-bit regesters
		uint8_t a; //GP
		uint8_t b; //GP
		uint8_t c; //GP
		uint8_t d; //GP
		uint8_t e; //GP
		uint8_t h; //GP
		uint8_t l; //GP
		uint8_t f; //FLAGS
		
		//16-bit registers
		uint16_t pc; //Program Counter
		uint16_t sp; //Stack Pointer

		//Clocks
		int m;//Incrementer
		int t;//Incrementer
		int m_clock;//Clock
		int t_clock;//Clock
		//Functions
		void step();
		void reset();
		void processOpcode(uint8_t opcode);
		LR35902Cpu();
		bool running;
		LR35902Memory memory;
};

#endif
