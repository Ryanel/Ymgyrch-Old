#ifndef MEMORY_8086_H
#define MEMORY_8086_H
#include <string>
#include <stdint.h>
using namespace std;
class I8086Memory
{
	public:
		//Flat Memory Functions
		uint8_t fread(int location); 
		uint8_t fwrite(int location);
};

#endif
