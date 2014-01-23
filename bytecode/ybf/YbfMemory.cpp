#include <ybf/YbfCpu.h>
#include <ybf/YbfMemory.h>
#include <fstream>
using namespace std;
uint8_t YbfMemory::fread8(int location)
{
	if(location < YBF_MEMORY_MAX)
	{
		return ram[location];
	}
	return 0;
} 
uint8_t YbfMemory::fwrite8(int location,uint8_t data)
{
	if (location > YBF_MEMORY_MAX)
	{
		return 1;
	}
	ram[location] = data;
	return 0;
}
uint16_t YbfMemory::fread16(int location)
{
	return fread8(location) + (fread8(location + 1) << 8);
}
uint16_t YbfMemory::fwrite16(int location,uint16_t data)
{
	return 0;
}
void YbfMemory::loadRom(string location)
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
void YbfMemory::clear()
{
	//TODO: CLEAR MEMORY
}
