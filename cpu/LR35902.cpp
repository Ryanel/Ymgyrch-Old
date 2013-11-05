#include <LR35902.h>
#include <LR35902Memory.h>
#include <stdio.h>
using namespace std;
LR35902Cpu::LR35902Cpu() //Put init stuff here
{
	printf("PC\t|OP\t|Ins.\n");
	printf("--------|-------|-------\n");
	running=true;
	memory.fwrite8(0,1);
}
void LR35902Cpu::step() //Called every frame
{
	processOpcode(memory.fread8(pc));
	pc &= 65535;
	m_clock+=m;
	t_clock+=t;
}
void LR35902Cpu::reset() //Reset everything
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
		m=0;
		t=0;
}

void LR35902Cpu::debugOpcode(string name, uint8_t opcode)
{
	printf("0x%X\t|0x%X\t|%s\n",pc,opcode,name.c_str());
}

void LR35902Cpu::processOpcode(uint8_t opcode)
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
			printf("0x%X\t|0x%X\t|??? \t<-- Unknown Opcode: Inserting halt!\n",pc,opcode);
			memory.fwrite8(pc,0x76);
	}
}
