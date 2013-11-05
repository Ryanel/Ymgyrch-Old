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
	R++;
	processOpcode(memory.fread8(pc));
	if(pc==16)
	{
		running=false;
	}
	pc &= 65535;
}
void Z80Cpu::reset() //Reset everything
{
		a=0;
		b=3;
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
		memory.clear();
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
		//
		case 0x7F: // A <- A
			debugOpcode("ld A,A",opcode); pc++;
			a=a;
			break;
		case 0x78: // A <- B
			debugOpcode("ld A,B",opcode); pc++;
			a=b;
			break;
		case 0x79: // A <- C
			debugOpcode("ld A,C",opcode); pc++;
			a=c;
			break;
		case 0x7A: // A <- D
			debugOpcode("ld A,D",opcode); pc++;
			a=d;
			break;
		case 0x7B: // A <- E
			debugOpcode("ld A,E",opcode); pc++;
			a=e;
			break;
		case 0x7C: // A <- H
			debugOpcode("ld A,H",opcode); pc++;
			a=h;
			break;
		case 0x7D: // A <- L
			debugOpcode("ld A,L",opcode); pc++;
			a=l;
			break;
		case 0x7E: // A <- HL
			debugOpcode("ld A,(HL)",opcode); pc++;
			a=h * l; //TODO: Implement
			break;
			//B
		case 0x47: // B <- A
			debugOpcode("ld B,A",opcode); pc++;
			b=a;
			break;
		case 0x40: // B <- B
			debugOpcode("ld B,B",opcode); pc++;
			b=b;
			break;
		case 0x41: // B <- C
			debugOpcode("ld B,C",opcode); pc++;
			b=c;
			break;
		case 0x42: // B <- D
			debugOpcode("ld B,D",opcode); pc++;
			b=d;
			break;
		case 0x43: // B <- E
			debugOpcode("ld B,E",opcode); pc++;
			b=e;
			break;
		case 0x44: // B <- H
			debugOpcode("ld B,H",opcode); pc++;
			b=h;
			break;
		case 0x45: // B <- L
			debugOpcode("ld B,L",opcode); pc++;
			b=l;
			break;
		case 0x46: // B <- HL
			debugOpcode("ld B,(HL)",opcode); pc++;
			b=h * l; //TODO: Implement
			break;
			//C
		case 0x4F: // C <- A
			debugOpcode("ld C,A",opcode); pc++;
			c=a;
			break;
		case 0x48: // C <- B
			debugOpcode("ld C,B",opcode); pc++;
			c=b;
			break;
		case 0x49: // C <- C
			debugOpcode("ld C,C",opcode); pc++;
			c=c;
			break;
		case 0x4A: // C <- D
			debugOpcode("ld C,D",opcode); pc++;
			c=d;
			break;
		case 0x4B: // C <- E
			debugOpcode("ld C,E",opcode); pc++;
			c=e;
			break;
		case 0x4C: // C <- H
			debugOpcode("ld C,H",opcode); pc++;
			c=h;
			break;
		case 0x4D: // C <- L
			debugOpcode("ld C,L",opcode); pc++;
			c=l;
			break;
		case 0x4E: // C <- HL
			debugOpcode("ld C,(HL)",opcode); pc++;
			c=h * l; //TODO: Implement
			break;
		// D
		case 0x57: // D <- A
			debugOpcode("ld D,A",opcode); pc++;
			d=a;
			break;
			//D
		case 0x50: // D <- B
			debugOpcode("ld D,B",opcode); pc++;
			d=b;
			break;
		case 0x51: // D <- C
			debugOpcode("ld D,C",opcode); pc++;
			d=c;
			break;
		case 0x52: // D <- D
			debugOpcode("ld D,D",opcode); pc++;
			d=d;
			break;
		case 0x53: // D <- E
			debugOpcode("ld D,E",opcode); pc++;
			d=e;
			break;
		case 0x54: // D <- H
			debugOpcode("ld D,H",opcode); pc++;
			d=h;
			break;
		case 0x55: // D <- L
			debugOpcode("ld D,L",opcode); pc++;
			d=l;
			break;
		case 0x56: // D <- HL
			debugOpcode("ld D,(HL)",opcode); pc++;
			d=h * l; //TODO: Implement
			break;
			// E
		case 0x5F: // E <- A
			debugOpcode("ld E,A",opcode); pc++;
			e=a;
			break;
		case 0x58: // E <- B
			debugOpcode("ld E,B",opcode); pc++;
			e=b;
			break;
		case 0x59: // E <- C
			debugOpcode("ld E,C",opcode); pc++;
			e=c;
			break;
		case 0x5A: // E <- D
			debugOpcode("ld E,D",opcode); pc++;
			e=d;
			break;
		case 0x5B: // E <- E
			debugOpcode("ld E,E",opcode); pc++;
			e=e;
			break;
		case 0x5C: // E <- H
			debugOpcode("ld E,H",opcode); pc++;
			e=h;
			break;
		case 0x5D: // E <- L
			debugOpcode("ld E,L",opcode); pc++;
			e=l;
			break;
		case 0x5E: // E <- HL
			debugOpcode("ld E,(HL)",opcode); pc++;
			e=h * l; //TODO: Implement
			break;
			// H
		case 0x67: // H <- A
			debugOpcode("ld H,A",opcode); pc++;
			h=a;
			break;
		case 0x60: // H <- B
			debugOpcode("ld H,B",opcode); pc++;
			h=b;
			break;
		case 0x61: // H <- C
			debugOpcode("ld H,C",opcode); pc++;
			h=c;
			break;
		case 0x62: // H <- D
			debugOpcode("ld H,D",opcode); pc++;
			h=d;
			break;
		case 0x63: // H <- E
			debugOpcode("ld H,E",opcode); pc++;
			h=e;
			break;
		case 0x64: // H <- H
			debugOpcode("ld H,H",opcode); pc++;
			h=h;
			break;
		case 0x65: // H <- L
			debugOpcode("ld H,L",opcode); pc++;
			h=l;
			break;
		case 0x66: // H<- HL
			debugOpcode("ld H,(HL)",opcode); pc++;
			h=h * l; //TODO: Implement
			break;
			// L
		case 0x6F: // L <- A
			debugOpcode("ld L,A",opcode); pc++;
			l=a;
			break;
		case 0x68: // L <- B
			debugOpcode("ld L,B",opcode); pc++;
			l=b;
			break;
		case 0x69: // L <- C
			debugOpcode("ld L,C",opcode); pc++;
			l=c;
			break;
		case 0x6A: // L <- D
			debugOpcode("ld L,D",opcode); pc++;
			l=d;
			break;
		case 0x6B: // L <- E
			debugOpcode("ld L,E",opcode); pc++;
			l=e;
			break;
		case 0x6C: // L <- H
			debugOpcode("ld L,H",opcode); pc++;
			l=h;
			break;
		case 0x6D: // L <- L
			debugOpcode("ld L,L",opcode); pc++;
			l=l;
			break;
		case 0x6E: // L<- HL
			debugOpcode("ld L,(HL)",opcode); pc++;
			l=h * l; //TODO: Implement
			break;
			// HL
		case 0x77: // HL <- A //TODO: ld HL,{}
			debugOpcode("ld L,A",opcode); pc++;
			l=a;
			break;
		case 0x70: // HL <- B
			debugOpcode("ld L,B",opcode); pc++;
			l=b;
			break;
		case 0x71: // HL <- C
			debugOpcode("ld L,C",opcode); pc++;
			l=c;
			break;
		case 0x72: // Hl <- D
			debugOpcode("ld L,D",opcode); pc++;
			l=d;
			break;
		case 0x73: // L <- E
			debugOpcode("ld L,E",opcode); pc++;
			l=e;
			break;
		case 0x74: // L <- H
			debugOpcode("ld L,H",opcode); pc++;
			l=h;
			break;
		case 0x75: // L <- L
			debugOpcode("ld L,L",opcode); pc++;
			l=l;
			break;
		default:
			printf("0x%X\t|0x%X\t|??? \t<-- Unsupported Instruction: halt!\n",pc,opcode);
			processOpcode(0x76);
	}
}
