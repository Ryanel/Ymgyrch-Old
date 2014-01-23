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
	processOpcode(memory.fread8(pc));
	pc &= 65535;
}
void YbfCpu::reset() //Reset everything
{

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
/*
void YbfCpu::debugOpcode24(string name,uint16_t operand, uint8_t opcode)
{
	printf("0x%X\t|0x%X\t|%s 0x%X\n",pc,opcode,name.c_str(),operand);
}
*/
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
			debugOpcode("waiti (unimp)", opcode);
			pc++;
			break;
		//inc
		case 0x01:
			debugOpcode16("inc R #",memory.fread16(pc + 1), opcode);
			R[memory.fread8(pc + 1)]=R[memory.fread8(pc + 1)]+memory.fread8(pc + 2);
			pc+=3;
			break;
		case 0x11:
			debugOpcode16("inc R ##",memory.fread16(pc + 1), opcode);
			R[memory.fread8(pc + 1)]=R[memory.fread8(pc + 1)]+memory.fread16(pc + 2);
			pc+=4;
			break;
		//dec
		case 0x02:
			debugOpcode16("dec R #",memory.fread16(pc + 1), opcode);
			R[memory.fread8(pc + 1)]=R[memory.fread8(pc + 1)]-memory.fread8(pc + 2);
			pc+=3;
			break;
		case 0x12:
			debugOpcode16("dec R ##",memory.fread16(pc + 1), opcode);
			R[memory.fread8(pc + 1)]=R[memory.fread8(pc + 1)]-memory.fread16(pc + 2);
			pc+=4;
			break;
		default:
			printf("0x%X\t|0x%X\t|??? \t<-- Unknown Opcode: Inserting halt!\n",pc,opcode);
			processOpcode(0x10);
			break;
	}
}
