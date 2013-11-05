#include <stdio.h>
#include <LR35902.h>
#include <cstring>
void gameboy();
int main(int argc, char* argv[])
{
	printf("Ymgyrch v. 0.0.0.1 - alpha (git)\n");
	if(0)
	{
		printf("usage: %s {options} [path to executable]\n",argv[0]);
		return 1;
	}
	//TODO: DETECT System
	gameboy();
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
		cpu.pc &= 65535;
	}
}