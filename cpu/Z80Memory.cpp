#include <iostream>
#include <fstream>
#include <Z80Memory.h>
using namespace std;
uint8_t Z80Memory::fread8(int location)
{
	return ram[location];
} 
uint8_t Z80Memory::fwrite8(int location,uint8_t data)
{
	ram[location]=data;
	return 0;
}
uint16_t Z80Memory::fread16(int location)
{
	return fread8(location) + (fread8(location + 1) << 8);
}
uint16_t Z80Memory::fwrite16(int location,uint16_t data)
{
	return 0;
}
void Z80Memory::loadRom(string location, int start)
{
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
	//TODO: CLEAR MEMORY
}
