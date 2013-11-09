#include <ybf/YbfCpu.h>
#include <GenericCpu.h>
#include <stdio.h>
using namespace std;
YbfCpu::YbfCpu() //Put init stuff here
{
	printf("PC\t|OP\t|Ins.\n");
	printf("--------|-------|-------\n");
	running=true;
}
void YbfCpu::step() //Called every frame
{

}
void YbfCpu::reset() //Reset everything
{

		a=0;
		b=0;
		c=0;
		d=0;
		s=0;
		pc=0;
		sp=0;

}

void YbfCpu::debugOpcode(string name, uint8_t opcode)
{
	printf("0x%X\t|0x%X\t|%s\n",pc,opcode,name.c_str());
}

void YbfCpu::debugOpcode8(string name,uint8_t operand, uint8_t opcode)
{
	printf("0x%X\t|0x%X\t|%s 0x%X\n",pc,opcode,name.c_str(),operand);
}
void YbfCpu::debugOpcode16(string name,uint16_t operand, uint8_t opcode)
{
	printf("0x%X\t|0x%X\t|%s 0x%X\n",pc,opcode,name.c_str(),operand);
}

void YbfCpu::processOpcode(uint8_t opcode)
{
	switch(opcode)
	{
		//sys
		case 0x00:
			debugOpcode("nop", opcode);
			pc++;
			break;
		case 0x10:
			debugOpcode("hlt", opcode);
			pc++;
			running=false;
			break;
		case 0x20:
			debugOpcode("waiti", opcode);
			running=false;
			break;
		//inc

		default:
			printf("0x%X\t|0x%X\t|??? \t<-- Unknown Opcode: Inserting halt!\n",pc,opcode);
			//memory.fwrite8(pc,0x76);
	}
}
