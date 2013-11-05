#include <Z80.h>
#include <GenericCpu.h>
#include <stdio.h>
using namespace std;
Z80Cpu::Z80Cpu() //Put init stuff here
{
	printf("PC\t|OP\t|Ins.\n");
	printf("--------|-------|-------\n");
	running=true;
}
void Z80Cpu::step() //Called every frame
{
	processOpcode(0x76);
	pc &= 65535;
}
void Z80Cpu::reset() //Reset everything
{
		a=0;
		b=0;
		c=0;
		d=0;
		e=0;
		h=0;
		l=0;
		f=0; 
		pc=0;
		sp=0;
		I=0;
		R=0;
		IX=0;
		IY=0;

}

void Z80Cpu::debugOpcode(string name, uint8_t opcode)
{
	printf("0x%X\t|0x%X\t|%s\n",pc,opcode,name.c_str());
}

void Z80Cpu::processOpcode(uint8_t opcode)
{
	switch(opcode)
	{
		case 0x00: //NOP
			debugOpcode("nop",opcode);
			pc++;
			break;
		case 0x76: //HALT
			debugOpcode("halt \t<-- End of Execution",opcode);
			running=false;
			break;
		
		default:
			printf("0x%X\t|0x%X\t|??? \t<-- Unknown Opcode: halt!\n",pc,opcode);
			processOpcode(0x76);
	}
}
