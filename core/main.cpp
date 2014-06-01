#include <stdio.h>
#include <GenericSystem.h>
#include <cstring>
#include <string>
#include <ctime>
#include <unistd.h>

#include <system/GenericZ80.h>

using namespace std;

//Options
bool benchmark = false;

uint32_t system_id = 0;
string image_name="";

int executeSystem(uint32_t id)
{
	GenericSystem * system;
	switch(id)
	{
		case 0x0: // Unknown System
			printf("error: No system selected.\n");
			return 2;
		case 0x1: // Generic Z80 CPU
			system = new GenericZ80(image_name);
			system->run();
			break;
		default:
			printf("error: Unknown system selected.\n");
			return 2;
	}
	
	return 0;
}

uint32_t parseSystem(string name)
{
	if(strcmp("z80",name.c_str()) == 0)
	{
		return 0x1;
	}
	return 0x0;
}

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		printf("usage: %s {options} [path to executable]\n",argv[0]);
		return 1;
	}
	int i = 1;
	while(i!=argc)
	{
		if(strcmp("-bench",argv[i])==0)
		{
			printf("bench: enabled\n");
			benchmark = 1000;
		}
		else if(strcmp("-m",argv[i])==0)
		{
			system_id = parseSystem(argv[++i]);
		}
		else
		{
			image_name = argv[i];
		}
		i++;
	}
	return executeSystem(system_id);
}
