#include <stdio.h>
int main(int argc, char* argv[])
{
	int realargc = argc - 1;
	printf("Ymgyrch v. 0.0.0.1 - alpha (git)\n");
	if(!realargc)
	{
		printf("usage: %s {options} [path to executable]\n",argv[0]);
		return 0;
	}
	if (true)
	{
		return 0;
	}
	//TODO: Detect parser to use.
	//TODO: Make emulation engine
	while(true)
	{
	}
}
