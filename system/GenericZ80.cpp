#include <system/GenericZ80.h>
#include <Z80.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
GenericZ80::GenericZ80(const string filename) : GenericSystem(filename)
{
	cpu = new Z80Cpu();
	cpu->reset();
	cpu->running=true;
	cpu->memory.loadRom(filename,0);
}

void GenericZ80::run()
{
	while(cpu->running)
	{
		cpu->step();
		usleep(50000);
	}
	printf("a:0x%X\tb:0x%X\tc:0x%X\td:0x%X\te:0x%X\th:0x%X\tl:0x%X\tpc:0x%X sp:0x%X\n",cpu->a,cpu->b,cpu->c,cpu->d,cpu->e,((cpu->hl & 0xFF00) >> 8), (cpu->hl & 0x00FF),cpu->pc,cpu->sp);

}