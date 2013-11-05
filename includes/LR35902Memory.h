#ifndef LR35902_8086_H
#define LR35902_8086_H
#include <string>
#include <stdint.h>
using namespace std;
class LR35902Memory
{
	public:
		//Flat Memory Functions
		uint8_t fread8(int location); 
		uint8_t fwrite8(int location);
		uint16_t fread16(int location); 
		uint16_t fwrite16(int location);
};

#endif
