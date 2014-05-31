#include <iostream>
#include <fstream>
#include <Z80Memory.h>
using namespace std;
uint8_t Z80Memory::fread8(uint16_t location)
{
	return ram[location];
} 
uint8_t Z80Memory::fwrite8(uint16_t location,uint8_t data)
{
	ram[location]=data;
	return 0;
}
uint16_t Z80Memory::fread16(uint16_t location)
{
	return (fread8(location + 1) << 8) + fread8(location);
}
uint16_t Z80Memory::fwrite16(uint16_t location,uint16_t data)
{
	ram[location]=data;
	return 0;
}
void Z80Memory::loadRom(string location, uint16_t start)
{
	clear();
	ifstream in(location.c_str());
	unsigned char temp=0;
	int to=0;
	if (in)
	{
		while(in.good())
		{
			in.read(reinterpret_cast<char *>(&temp), 1) ;
			ram[to]=temp;
			to++;
		}
	}
}
void Z80Memory::clear()
{
	int i=0;
	while(Z80_MEMORY_MAX-1 != i)
	{
		ram[i]=0;
		i++;
	}
	ram[0x7A00] = 0x76;

}
