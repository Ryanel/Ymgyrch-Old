#include <stdio.h>
#include <cstring>
#include <bytecode/smtl/SmtlCpu.h>
int main(int argc, char* argv[])
{
	int realargc = argc - 1;
	printf("Ymgyrch v. 0.0.0.1 - alpha (git)\n");
	if(0)
	{
		printf("usage: %s {options} [path to executable]\n",argv[0]);
		return 0;
	}
	SmtlCpu cpu;
	int n;
	for( n = 1; n < argc; n++)
	{
		if(strcmp(argv[n],"-debug")==0)
		{
			cpu.isDebugging=true;
		}
		else if(strcmp(argv[n],"-bin")==0)
		{
			printf("Unable to load file into memory: unimplemented!\n");
			return 1;
		}
		else if(strcmp(argv[n],"-step")==0)
		{
			printf("[?]:Stepping enabled!\n");
			return 1;
		}
		else
		{
			printf("[!]%s is not a valid option! Ignoring\n",argv[n]);
		}
		
	}
	
	cpu.executeBios("\0");

	while(cpu.isExecuting)
	{
		cpu.step();
	}
}

