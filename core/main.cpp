#include <stdio.h>
#include <LR35902.h>
#include <Z80.h>
#include <cstring>

void z80(string filename);
void gameboy(string filename);
void z80(string filename)
{
	printf("Emulating a Z80\n");
	Z80Cpu cpu;
	cpu.reset();
	cpu.running=true;
	cpu.memory.loadRom(filename,0);
	while(cpu.running)
	{
		cpu.step();
	}
	printf("a:0x%X\tb:0x%X\tc:0x%X\td:0x%X\te:0x%X\th:0x%X\tl:0x%X\tpc:0x%X\n",cpu.a,cpu.b,cpu.c,cpu.d,cpu.e,cpu.h,cpu.l,cpu.pc);
}

void gameboy(string filename)
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

int main(int argc, char* argv[])
{
	printf("Ymgyrch v. 0.0.0.1 - alpha (git)\n");
	if(0)
	{
		printf("usage: %s {options} [path to executable]\n",argv[0]);
		return 1;
	}
	//TODO: DETECT System
	int i=1;
	int id=0;
	string filename="";
	while(i!=argc)
	{
		if(strcmp("-z80",argv[i])==0)
		{
			printf("CPU: Z80\n");
			id = 1;
		}
		else if (strcmp("--gameboy",argv[i])==0)
		{
			id = 2;
		}
		else if (strcmp("--lr35902",argv[i])==0)
		{
			id = 2;
		}
		else if (strcmp("--8086",argv[i])==0)
		{
			id = 3;
		}
		else
		{
			filename = argv[i];
		}
		i++;
	}
	if(strcmp("",filename.c_str())==0)
	{
		printf("No filename specified!\n");
		return 1;
	}
	switch(id)
	{
		case 0x1: // Z80
			z80(filename);
			break;
		case 0x2: // Gameboy
			gameboy(filename);
			break;
		default:
			printf("No cpu specified! Try -z80\n");
			break;

	}
	//z80();
}
