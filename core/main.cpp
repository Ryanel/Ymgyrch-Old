#include <stdio.h>
#include <LR35902.h>
#include <Z80.h>
#include <cstring>
void gameboy();
void z80();
int main(int argc, char* argv[])
{
	printf("Ymgyrch v. 0.0.0.1 - alpha (git)\n");
	if(0)
	{
		printf("usage: %s {options} [path to executable]\n",argv[0]);
		return 1;
	}
	//TODO: DETECT System
	z80();
}

void z80()
{
	printf("Emulating a Z80\n");
	Z80Cpu cpu;
	cpu.reset();
	cpu.running=true;
	cpu.processOpcode(0x0);
	cpu.processOpcode(0x7F);
	cpu.processOpcode(0x4);
	while(cpu.running)
	{
		cpu.step();
	}
}

void gameboy()
{
	printf("Emulating a LR35902 (Gameboy)\n");
	LR35902Cpu cpu;
	cpu.reset();
	cpu.memory.cpu_point=&cpu;
	cpu.running=true;
	while(cpu.running)
	{
		cpu.step();
	}
}