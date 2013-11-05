#ifndef LR35902_CPU_H
#define LR35902_CPU_H
#include <string>
using namespace std;
class LR35902Cpu
{
	private:
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
		int m;
		int t;
	public:
		void step();
		void reset();
		LR35902Memory memory;
};

#endif
