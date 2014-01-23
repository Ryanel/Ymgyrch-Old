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
			//===================
			//SYS
			//===================
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
			//===================
			//ADD
			//===================
		case 0x01:
			debugOpcode16("add R #",memory.fread16(pc + 1), opcode);
			R[memory.fread8(pc + 1)]=R[memory.fread8(pc + 1)]+memory.fread8(pc + 2);
			pc+=3;
			break;
		case 0x11:
			debugOpcode16("add R (##)",memory.fread16(pc + 1), opcode);
			R[memory.fread8(pc + 1)]=R[memory.fread8(pc + 1)]+memory.fread16(memory.fread16(pc + 2));
			pc+=4;
			break;
		case 0x21:
			debugOpcode16("add R R",memory.fread16(pc + 1), opcode);
			R[memory.fread8(pc + 1)]=R[memory.fread8(pc + 1)] + R[memory.fread8(pc + 2)];
			pc+=3;
			break;
		case 0x31:
			debugOpcode16("add (##) #",memory.fread16(pc + 1), opcode);
			memory.fwrite8(memory.fread16(pc + 1),(memory.fread8(memory.fread16(pc + 1)) + memory.fread8(pc + 2)));
			pc+=4;
			break;
		case 0x41:
			debugOpcode16("add (##) R",memory.fread16(pc + 1), opcode);
			memory.fwrite8(memory.fread16(pc + 1),(memory.fread8(memory.fread16(pc + 1)) + R[memory.fread8(pc + 2)]));
			pc+=4;
			break;
		case 0x51:
			debugOpcode8("add (I) R",memory.fread8(pc + 1), opcode);
			memory.fwrite8(I,memory.fread8(I) + R[memory.fread8(pc + 1)]);
			pc+=3;
			break;
		case 0x61:
			debugOpcode8("add (I) #",memory.fread8(pc + 1), opcode);
			memory.fwrite8(I,memory.fread8(I) + memory.fread8(pc + 1));
			pc+=3;
			break;
			//===================
			//SUB
			//===================
		case 0x02:
			debugOpcode16("sub R #",memory.fread16(pc + 1), opcode);
			R[memory.fread8(pc + 1)]=R[memory.fread8(pc + 1)]-memory.fread8(pc + 2);
			pc+=3;
			break;
		case 0x12:
			debugOpcode16("sub R ##",memory.fread16(pc + 1), opcode);
			R[memory.fread8(pc + 1)]=R[memory.fread8(pc + 1)]-memory.fread16(memory.fread16(pc + 2));
			pc+=4;
			break;
		case 0x22:
			debugOpcode16("sub R R",memory.fread16(pc + 1), opcode);
			R[memory.fread8(pc + 1)]=R[memory.fread8(pc + 1)] - R[memory.fread8(pc + 2)];
			pc+=3;
			break;
		case 0x32:
			debugOpcode16("sub (##) #",memory.fread16(pc + 1), opcode);
			memory.fwrite8(memory.fread16(pc + 1),(memory.fread8(memory.fread16(pc + 1)) - memory.fread8(pc + 2)));
			pc+=4;
			break;
		case 0x42:
			debugOpcode16("sub (##) R",memory.fread16(pc + 1), opcode);
			memory.fwrite8(memory.fread16(pc + 1),memory.fread8(memory.fread16(pc + 1)) - R[memory.fread8(pc + 2)]);
			pc+=4;
			break;
		case 0x52:
			debugOpcode8("sub (I) R",memory.fread8(pc + 1), opcode);
			memory.fwrite8(I,memory.fread8(I) - R[memory.fread8(pc + 1)]);
			pc+=3;
			break;
		case 0x62:
			debugOpcode8("sub (I) #",memory.fread8(pc + 1), opcode);
			memory.fwrite8(I,memory.fread8(I) - memory.fread8(pc + 1));
			pc+=3;
			break;
			//===================
			//LD
			//===================
		default:
			printf("0x%X\t|0x%X\t|??? \t<-- Unknown Opcode: Inserting halt!\n",pc,opcode);
			processOpcode(0x10);
			break;
	}
}
