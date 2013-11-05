#ifndef LR35902_8086_H
#define LR35902_8086_H
#include <string>
#include <stdint.h>
#include <LR35902.h>
#include <LR35902Memory.h>
using namespace std;
class LR35902Cpu;
class LR35902Memory
{
	
	private:
		bool inBios;
		uint8_t bios[];
		uint8_t rom[];
		uint8_t wram[];
		uint8_t eram[];
		uint8_t zram[];
		uint8_t vram[];
	public:
		//Flat Memory Functions
		uint8_t fread8(int location); 
		uint8_t fwrite8(int location);
		uint16_t fread16(int location); 
		uint16_t fwrite16(int location);
		void loadRom(string location);
		LR35902Cpu *cpu_point;
};

#endif
