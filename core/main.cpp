#include <stdio.h>
#include <Z80.h>
#include <ybf/YbfCpu.h>
#include <cstring>
#include <ctime>
#include <unistd.h>
using namespace std;

void z80(string filename);
void gameboy(string filename);
void ybf(string filename);

//options
int benchmark=0;
void z80(string filename)
{
	printf("Emulating a Z80\n");
	Z80Cpu cpu;
	cpu.reset();
	cpu.running=true;
	cpu.memory.loadRom(filename,0);
	if(benchmark)
	{
		int count = 0;
		int max = benchmark;
		clock_t starttime = clock();
		while(count!=max && cpu.running)
		{
			cpu.step();
			count++;
		}
		clock_t endtime = clock();
		printf("a:0x%X\tb:0x%X\tc:0x%X\td:0x%X\te:0x%X\th:0x%X\tl:0x%X\tpc:0x%X\n",cpu.a,cpu.b,cpu.c,cpu.d,cpu.e,((cpu.hl & 0xFF00) >> 8), (cpu.hl & 0x00FF),cpu.pc);
		printf("Emulated cycles: %d\n",count);
		printf("Time taken: %d clocks\n",(int)(endtime - starttime));
		return;
	}
	while(cpu.running)
	{
		cpu.step();
	}
	printf("a:0x%X\tb:0x%X\tc:0x%X\td:0x%X\te:0x%X\th:0x%X\tl:0x%X\tpc:0x%X\n",cpu.a,cpu.b,cpu.c,cpu.d,cpu.e,((cpu.hl & 0xFF00) >> 8), (cpu.hl & 0x00FF),cpu.pc);

}

void gameboy(string filename)
{
	/*
	printf("Emulating a LR35902 (Gameboy)\n");
	LR35902Cpu cpu;
	cpu.reset();
	cpu.memory.cpu_point=&cpu;
	cpu.running=true;
	while(cpu.running)
	{
		cpu.step();
	}
	*/
}

void ybf(string filename)
{
	printf("Running a YBF executable\n");
	YbfCpu cpu;
	cpu.reset();
	cpu.memory.loadRom(filename);
	cpu.running=true;
	while(cpu.running)
	{
		cpu.step();
	}
	printf("Execution Ended:\n");
	int i = 0;
	while(i!=16)
	{
		printf("R%d\t= 0x%X \t R%d\t= 0x%X\n",i,cpu.R[i],i,cpu.XR[i]);
		i++;
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
		if(strcmp("-bench",argv[i])==0)
		{
			printf("Benchmarking: enabled\n");
			benchmark = 1000;
		}
		else if(strcmp("-z80",argv[i])==0)
		{
			printf("CPU: Z80\n");
			id = 1;
		}
		else if (strcmp("-gameboy",argv[i])==0)
		{
			id = 2;
		}
		else if (strcmp("-lr35902",argv[i])==0)
		{
			id = 2;
		}
		else if (strcmp("-8086",argv[i])==0)
		{
			id = 3;
		}
		else if (strcmp("-ybf",argv[i])==0)
		{
			id = 4;
		}
		else
		{
			filename = argv[i];
		}
		if(strcmp("--help",argv[i])==0)
		{
			printf("Help:\n");
			printf("Every time you run Ymgyrch, you need to specifiy either the system or cpu, and the filename\n");
			printf("Avalable Bytecode Formats:\n");
			printf(" * -ybf\n");
			printf("Avalable CPU's:\n");
			printf(" * -z80\n");
			printf(" * -8086\n");
			printf(" * -lr35902\n");
			printf("Avalable System:\n");
			printf(" * -gameboy\n");
			return 0;
		}
		i++;
	}
	if(id == 0)
	{
		printf("No cpu specified! Try --help\n");
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
		case 0x4: // YBF
			ybf(filename);
			break;
		default:
			return 0x5;
			break;

	}
	//z80();
}
