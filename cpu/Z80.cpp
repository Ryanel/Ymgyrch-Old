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
			cycles += 4;
			break;
		case 0x76: //HALT
			debugOpcode("halt \t<-- End of Execution",opcode);
			running=false;
			break;
		
		//MOV Instructions
		case 0x7F: // A <- A
			debugOpcode("ld A,A",opcode);
			a=a;
			break;
		case 0x78: // A <- B
			debugOpcode("ld A,B",opcode);
			a=b;
			break;
		case 0x79: // A <- C
			debugOpcode("ld A,C",opcode);
			a=c;
			break;
		case 0x7A: // A <- D
			debugOpcode("ld A,D",opcode);
			a=d;
			break;
		case 0x7B: // A <- E
			debugOpcode("ld A,E",opcode);
			a=e;
			break;
		case 0x7C: // A <- H
			debugOpcode("ld A,H",opcode);
			a=h;
			break;
		case 0x7D: // A <- L
			debugOpcode("ld A,L",opcode);
			a=l;
			break;
		case 0x7E: // A <- HL
			debugOpcode("ld A,(HL)",opcode);
			a=h * l; //TODO: Implement
			break;
		case 0x47: // B <- A
			debugOpcode("ld A,A",opcode);
			b=a;
			break;
		case 0x40: // B <- B
			debugOpcode("ld A,B",opcode);
			b=b;
			break;
		case 0x41: // B <- C
			debugOpcode("ld A,C",opcode);
			b=c;
			break;
		case 0x42: // B <- D
			debugOpcode("ld A,D",opcode);
			b=d;
			break;
		case 0x43: // B <- E
			debugOpcode("ld A,E",opcode);
			b=e;
			break;
		case 0x44: // B <- H
			debugOpcode("ld A,H",opcode);
			b=h;
			break;
		case 0x45: // B <- L
			debugOpcode("ld A,L",opcode);
			b=l;
			break;
		case 0x46: // B <- HL
			debugOpcode("ld A,(HL)",opcode);
			b=h * l; //TODO: Implement
			break;

		default:
			printf("0x%X\t|0x%X\t|??? \t<-- Unknown Opcode: halt!\n",pc,opcode);
			processOpcode(0x76);
	}
}
