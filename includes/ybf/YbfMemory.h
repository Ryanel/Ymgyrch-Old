#ifndef MEMORY_YBF_H
#define MEMORY_YBF_H
#include <string>
#include <stdint.h>
using namespace std;
#define YBF_MEMORY_MAX 65535
class YbfMemory
{
	
	private:
		uint8_t ram[YBF_MEMORY_MAX];
	public:
		//Flat Memory Functions
		uint8_t fread8(int location); 
		uint8_t fwrite8(int location,uint8_t data);
		uint16_t fread16(int location); 
		uint16_t fwrite16(int location,uint16_t data);
		void loadRom(string location);
		void clear();
};

#endif
