#ifndef MEMORY_Z80_H
#define MEMORY_Z80_H
#include <string>
#include <stdint.h>
using namespace std;

#define Z80_MEMORY_MAX 0xFFFF
class Z80Memory
{
	
	private:
		uint8_t ram[Z80_MEMORY_MAX];
	public:
		//Flat Memory Functions
		uint8_t fread8(uint16_t location); 
		uint8_t fwrite8(uint16_t location,uint8_t data);
		uint16_t fread16(uint16_t location); 
		uint16_t fwrite16(uint16_t location,uint16_t data);
		void loadRom(string location,uint16_t start);
		void clear();
};

#endif
