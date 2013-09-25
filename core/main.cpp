#include <stdio.h>
#include <bytecode/ybf/YbfParser.h>
int main(int argc, char* argv[])
{
	int realargc = argc - 1;
	printf("Ymgyrch v. 0.0.0.1 - alpha (git)\n");
	if(!realargc)
	{
		printf("usage: %s {options} [path to executable]\n",argv[0]);
		return 0;
	}
	YbfParser ps;
	ps.loadInfo("sample/bytecode.yml");
	while(ps.execute())
	{
	}
}
