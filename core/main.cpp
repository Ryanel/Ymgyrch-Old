#include <stdio.h>
#include <bytecode/smtl/SmtlCpu.h>
int main(int argc, char* argv[])
{
	int realargc = argc - 1;
	printf("Ymgyrch v. 0.0.0.1 - alpha (git)\n");
	if(!realargc)
	{
		printf("usage: %s {options} [path to executable]\n",argv[0]);
		return 0;
	}
	SmtlCpu cpu;
	while(cpu.isExecuting)
	{
		cpu.step();
	}
}
