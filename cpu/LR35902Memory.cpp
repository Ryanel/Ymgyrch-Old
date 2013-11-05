#include <LR35902.h>
#include <LR35902Memory.h>
using namespace std;
uint8_t LR35902Memory::fread8(int location)
{
	switch(location & 0xF000)
	{
		case 0x0000:
			if(inBios)
			{
				if(location < 0x0100)
					return bios[location];
			}
			return rom[location];
		//ROM0
		case 0x1000:
		case 0x2000:
		case 0x3000:
			return rom[location];
		case 0x4000:
		case 0x5000:
		case 0x6000:
		case 0x7000:
			return rom[location];
		case 0x8000:
		case 0x9000:
			return vram[location & 0x1FFF];
		case 0xA000:
		case 0xB000:
			return eram[location & 0x1FFF];
		case 0xC000:
		case 0xD000:
			return wram[location & 0x1FFF];
		case 0xE000: //Shadow
			return wram[location & 0x1FFF];
		case 0xF000:
			switch(location & 0x0F00)
			{
				case 0x000: 
				case 0x100: 
				case 0x200: 
				case 0x300: 
				case 0x400: 
				case 0x500: 
				case 0x600:  
				case 0x700: 
				case 0x800: 
				case 0x900: 
				case 0xA00: 
				case 0xB00: 
				case 0xC00: 
				case 0xD00:
					return wram[location & 0x1FFF];
				case 0xE00:
					if(location < 0xFEA0)
						return 0; //TODO: GPU RAM
					else
						return 0; // <--- Expected
				case 0xF00:
					if(location >= 0xFF80)
					{
						return zram[location & 0x7F];
					}
					else
					{
						//TODO: IO
						//Currently Unhandled
						return 0;
					}
				break;
			}
	}
	return 0;
} 
uint8_t LR35902Memory::fwrite8(int location)
{
	return 0;
}
uint16_t LR35902Memory::fread16(int location)
{
	return fread8(location) + (fread8(location + 1) << 8);
}
uint16_t LR35902Memory::fwrite16(int location)
{
	return 0;
}
void LR35902Memory::loadRom(string location)
{
	return;
}
