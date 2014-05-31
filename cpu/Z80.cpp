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
	pc &= 65535;
}
void Z80Cpu::reset() //Reset everything
{
		a=0;
		b=0;
		c=0;
		d=0;
		e=0;
		hl=0;
		//TODO: CLEAR FLAGS
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
	printf("0x%04X\t|0x%02X\t|%s\n",pc,opcode,name.c_str());
}

void Z80Cpu::debugOpcode8(string name,uint8_t operand, uint8_t opcode)
{
	printf("0x%04X\t|0x%02X\t|%s 0x%X\n",pc,opcode,name.c_str(),operand);
}
void Z80Cpu::debugOpcode16(string name,uint16_t operand, uint8_t opcode)
{
	printf("0x%04X\t|0x%02X\t|%s 0x%X\n",pc,opcode,name.c_str(),operand);
}

void Z80Cpu::push8(uint8_t value)
{
	memory.fwrite8(sp,value);
	sp -= 1;
}
void Z80Cpu::push16(uint16_t value)
{
	memory.fwrite16(sp,value);
	sp -= 2;
}
uint16_t Z80Cpu::pop16()
{
	uint16_t ret = memory.fread16(sp);
	sp += 2;
	return ret;
}
uint8_t Z80Cpu::pop8()
{
	uint8_t ret = memory.fread8(sp);
	sp += 1;
	return ret;
}

void Z80Cpu::processOpcode(uint8_t opcode)
{
	uint8_t temp;
	uint16_t temp16;
	switch(opcode)
	{

		//------------------------------------
		//Control Instructions
		//------------------------------------
		

		case 0x00: //NOP
			debugOpcode("nop",opcode);
			pc++;
			cycles += 4;
			break;
		case 0x76: //HALT
			debugOpcode("halt \t<-- End of Execution",opcode);
			running=false;
			break;
		
		//------------------------------------
		//Branch Control Instructions
		//------------------------------------
		case 0xC3: //JP
			debugOpcode16("jp",memory.fread16(pc+1),opcode);
			pc=memory.fread16(pc+1);
			break;
		case 0xE9: //JP HL
			debugOpcode("jp (hl)",opcode);
			pc=hl;
			break;
		case 0xCA: //JP Z
			debugOpcode16("jp z",memory.fread16(pc+1),opcode);
			if(flag_zero)
			{
				pc=memory.fread16(pc+1);
			}
			else
			{
				pc+=3;
			}
			break;
		case 0xC2: //JP NZ
			debugOpcode16("jp nz",memory.fread16(pc+1),opcode);
			if(!flag_zero)
			{
				pc=memory.fread16(pc+1);
			}
			else
			{
				pc+=3;
			}
			break;
		case 0x10: //djnz
			debugOpcode8("djnz",memory.fread8(pc+1),opcode);
			b--;
			if(b)
			{
				pc+=memory.fread8(pc+1);
			}
			else
			{
				pc+=2;
			}
			break;
		//------------------------------------
		//LOAD Instructions (A)
		//------------------------------------
		
		case 0x01: // BC <- **
			debugOpcode16("ld bc",memory.fread16(pc+1),opcode);
			temp16 = memory.fread16(pc+1);
			c = temp16;
			b = temp16 >> 8;
			pc+=3;
			break;
		case 0x7F: // A <- A
			debugOpcode("ld A,A",opcode); pc++;
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
			
			temp = ((hl & 0xFF00) >> 8);
			a=temp;
			break;
		case 0x7D: // A <- L
			debugOpcode("ld A,L",opcode); pc++;
			
			temp = ((hl & 0x00FF));
			a=temp;
			break;
		case 0x7E: // A <- HL
			debugOpcode("ld A,(HL)",opcode); pc++;
			a=hl; //TODO: Implement
			break;

		//------------------------------------
		//LD B Instructions
		//------------------------------------
		
		case 0x47: // B <- A
			debugOpcode("ld B,A",opcode); pc++;
			b=a;
			break;
		case 0x40: // B <- B
			debugOpcode("ld B,B",opcode); pc++;
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
			
			temp = ((hl & 0xFF00) >> 8);
			b=temp;
			break;
		case 0x45: // B <- L
			debugOpcode("ld B,L",opcode); pc++;
			
			temp = ((hl & 0x00FF));
			b=temp;
			break;
		case 0x46: // B <- HL
			debugOpcode("ld B,(HL)",opcode); pc++;
			b=hl; //TODO: Implement
			break;

		//------------------------------------
		//LD C Instructions
		//------------------------------------
		
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
			
			temp = ((hl & 0xFF00) >> 8);
			c=temp;
			break;
		case 0x4D: // C <- L
			debugOpcode("ld C,L",opcode); pc++;
			
			temp = ((hl & 0x00FF));
			c=temp;
			break;
		case 0x4E: // C <- HL
			debugOpcode("ld C,(HL)",opcode); pc++;
			c=hl; //TODO: Implement
			break;

		//------------------------------------
		//LD D Instructions
		//------------------------------------
		
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
			break;
		case 0x53: // D <- E
			debugOpcode("ld D,E",opcode); pc++;
			d=e;
			break;
		case 0x54: // D <- H
			debugOpcode("ld D,H",opcode); pc++;
			
			temp = ((hl & 0xFF00) >> 8);
			d=temp;
			break;
		case 0x55: // D <- L
			debugOpcode("ld D,L",opcode); pc++;
			
			temp = ((hl & 0x00FF));
			d=temp;
			break;
		case 0x56: // D <- HL
			debugOpcode("ld D,(HL)",opcode); pc++;
			d=hl;
			break;

		//------------------------------------
		//LD E Instructions
		//------------------------------------
		
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
			break;
		case 0x5C: // E <- H
			debugOpcode("ld E,H",opcode); pc++;
			
			temp = ((hl & 0xFF00) >> 8);
			e=temp;
			break;
		case 0x5D: // E <- L
			debugOpcode("ld E,L",opcode); pc++;
			
			temp = ((hl & 0x00FF));
			e=temp;
			break;
		case 0x5E: // E <- HL
			debugOpcode("ld E,(HL)",opcode); pc++;
			e=hl;
			break;

		//------------------------------------
		//LD H Instructions
		//------------------------------------
		
		case 0x67: // H <- A
			debugOpcode("ld H,A",opcode); pc++;
			hl=((uint16_t)a << 8);
			break;
		case 0x60: // H <- B
			debugOpcode("ld H,B",opcode); pc++;
			hl=((uint16_t)b << 8);
			break;
		case 0x61: // H <- C
			debugOpcode("ld H,C",opcode); pc++;
			hl=((uint16_t)c << 8);
			break;
		case 0x62: // H <- D
			debugOpcode("ld H,D",opcode); pc++;
			hl=((uint16_t)d << 8);
			break;
		case 0x63: // H <- E
			debugOpcode("ld H,E",opcode); pc++;
			hl=((uint16_t)e << 8);
			break;
		case 0x64: // H <- H
			debugOpcode("ld H,H",opcode); pc++;
			break;
		case 0x65: // H <- L
			debugOpcode("ld H,L",opcode); pc++;
			
			temp16 = ((hl & 0x00FF) >> 8);
			hl=temp16;
			break;
		case 0x66: // H<- HL
			debugOpcode("ld H,(HL)",opcode); pc++;
			
			temp16 = ((hl & 0xFF00) >> 8);
			hl=temp16;
			break;

		//------------------------------------
		//LD L Instructions
		//------------------------------------
		
		case 0x6F: // L <- A
			debugOpcode("ld L,A",opcode); pc++;
			hl=a;
			break;
		case 0x68: // L <- B
			debugOpcode("ld L,B",opcode); pc++;
			hl=b;
			break;
		case 0x69: // L <- C
			debugOpcode("ld L,C",opcode); pc++;
			hl=c;
			break;
		case 0x6A: // L <- D
			debugOpcode("ld L,D",opcode); pc++;
			hl=d;
			break;
		case 0x6B: // L <- E
			debugOpcode("ld L,E",opcode); pc++;
			hl=e;
			break;
		case 0x6C: // L <- H
			debugOpcode("ld L,H",opcode); pc++;
			
			temp16 = ((hl & 0xFF00) >> 8);
			hl=temp16;
			break;
		case 0x6D: // L <- L
			debugOpcode("ld L,L",opcode); pc++;
			break;
		case 0x6E: // L<- HL
			debugOpcode("ld L,(HL)",opcode); pc++;
			
			temp = (hl & 0x00FF);

			hl=temp;
			break;

		//------------------------------------
		//LD HL Instructions
		//------------------------------------
			
		case 0x77: // HL <- A //TODO: ld HL,{}
			debugOpcode("ld L,A",opcode); pc++;
			hl = a & 0x00FF;
			break;
		case 0x70: // HL <- B
			debugOpcode("ld L,B",opcode); pc++;
			hl = b & 0x00FF;
			break;
		case 0x71: // HL <- C
			debugOpcode("ld L,C",opcode); pc++;
			hl = c & 0x00FF;
			break;
		case 0x72: // Hl <- D
			debugOpcode("ld L,D",opcode); pc++;
			hl = d & 0x00FF;
			break;
		case 0x73: // HL <- E
			debugOpcode("ld L,E",opcode); pc++;
			hl = e & 0x00FF;
			break;
		case 0x74: // HL <- H
			debugOpcode("ld L,H",opcode); pc++;
			hl = (hl & 0xFF00);
			break;
		case 0x75: // HL <- L
			debugOpcode("ld L,L",opcode); pc++;
			hl = (hl & 0x00FF) ;
			break;

		//------------------------------------
		//ADD  Instructions
		//------------------------------------

		case 0x87: // A <- A + A
			debugOpcode("add A,A",opcode); pc++;
			a=a+a;
			break;
		case 0x80: // A <- A + B
			debugOpcode("add A,B",opcode); pc++;
			a=a+a;
			break;
		case 0x81: // A <- A + C
			debugOpcode("add A,C",opcode); pc++;
			a=a+c;
			break;
		case 0x82: // A <- A + D
			debugOpcode("add A,D",opcode); pc++;
			a=a+d;
			break;
		case 0x83: // A <- A + E
			debugOpcode("add A,E",opcode); pc++;
			a=a+e;
			break;
		case 0x84: // A <- A + H
			debugOpcode("add A,H",opcode); pc++;
			a=a + (hl >> 8);
			break;
		case 0x85: // A <- A + L
			debugOpcode("add A,L",opcode); pc++;
			a= a + (uint8_t)(hl & 0x00FF);
			break;
		case 0x86: // A <- A + (HL)
			debugOpcode("add A,(HL)",opcode); pc++;
			a = a + hl;
			break;

		//------------------------------------
		//INC Increment Instructions
		//------------------------------------

		case 0x3C: // A <- A + 1
			debugOpcode("inc A",opcode); pc++;
			a+=1;
			if(a==0)
			{
				flag_carry=true;
			}
			break;
		case 0x04: // B <- B + 1
			debugOpcode("inc B",opcode); pc++;
			b+=1;
			if(b==0)
			{
				flag_carry=true;
			}
			break;
		case 0x0C: // C <- C + 1
			debugOpcode("inc C",opcode); pc++;
			c+=1;
			if(c==0)
			{
				flag_carry=true;
			}
			break;
		case 0x14: // D <- D + 1
			debugOpcode("inc D",opcode); pc++;
			d+=1;
			if(d==0)
			{
				flag_carry=true;
			}
			break;
		case 0x1C: // E <- E + 1
			debugOpcode("inc E",opcode); pc++;
			e+=1;
			if(e==0)
			{
				flag_carry=true;
			}
			break;
		case 0x24: // H <- H + 1
			debugOpcode("inc H",opcode); pc++;
			hl= (((hl >> 8) + 1 )<< 8);
			if(hl==0)
			{
				flag_carry=true;
			}
			break;
		case 0x2C: // L <- L + 1
			debugOpcode("inc L",opcode); pc++;
			hl =  (hl & 0x00FF) + 1;
			if(hl==0) //TODO: BUG: BITSET!
			{
				flag_carry=true;
			}
			break;
		case 0x34: // HL <- HL + 1
			debugOpcode("inc HL",opcode); pc++;
			hl += 1;
			if(hl==0)
			{
				flag_carry=true;
			}
			break;
		//------------------------------------
		//DEC Decrement Instructions
		//------------------------------------

		case 0x3D: // A <- A + 1
			debugOpcode("dec A",opcode); pc++;
			a-=1;

			if(a==0x0)
				flag_zero = true;
			else
				flag_zero = false;

			break;
		case 0x05: // B <- B + 1
			debugOpcode("dec B",opcode); pc++;
			b-=1;

			if(b==0x0)
				flag_zero = true;
			else
				flag_zero = false;
			
			break;
		case 0x0D: // C <- C + 1
			debugOpcode("dec C",opcode); pc++;
			c-=1;

			if(c==0x0)
				flag_zero = true;
			else
				flag_zero = false;
			
			break;
		case 0x15: // D <- D + 1
			debugOpcode("dec D",opcode); pc++;
			d-=1;

			if(d==0x0)
				flag_zero = true;
			else
				flag_zero = false;
			
			break;
		case 0x1D: // E <- E + 1
			debugOpcode("dec E",opcode); pc++;
			e-=1;

			if(e==0x0)
				flag_zero = true;
			else
				flag_zero = false;
			
			break;
		case 0x25: // H <- H + 1
			debugOpcode("dec H",opcode); pc++;
			hl= (((hl >> 8) - 1 ) << 8);

			if(hl==0x0)
				flag_zero = true;
			else
				flag_zero = false;
			
			break;
		case 0x2D: // L <- L + 1
			debugOpcode("dec L",opcode); pc++;
			hl =  (hl & 0x00FF) + 1;

			if(hl==0x0)
				flag_zero = true;
			else
				flag_zero = false;

			break;
		case 0x35: // HL <- HL + 1
			debugOpcode("dec HL",opcode); pc++;
			hl -= 1;

			if(hl==0x0)
				flag_zero = true;
			else
				flag_zero = false;

			break;

		//------------------------------------
		//MEM Memory Instructions
		//------------------------------------
		//LD Byte
		case 0x3E: //LD A *
			debugOpcode8("ld a",memory.fread8(pc+1), opcode);
			a = memory.fread8(pc+1);pc+=2;
			break;
		case 0x06: //LD B *
			debugOpcode8("ld b",memory.fread8(pc+1), opcode);
			b = memory.fread8(pc+1);pc+=2;
			break;
		case 0x0E: //LD C *
			debugOpcode8("ld c",memory.fread8(pc+1), opcode);
			c = memory.fread8(pc+1);pc+=2;
			break;
		case 0x16: //LD D *
			debugOpcode8("ld d",memory.fread8(pc+1), opcode);
			d = memory.fread8(pc+1);pc+=2;
			break;
		case 0x1E: //LD E *
			debugOpcode8("ld e",memory.fread8(pc+1), opcode);
			e = memory.fread8(pc+1);pc+=2;
			break;
		case 0x26: //LD H *
			debugOpcode8("ld h",memory.fread8(pc+1), opcode);
			hl = memory.fread8(pc+1)<< 8;pc+=2;
			break;
		case 0x2E: //LD L *
			debugOpcode8("ld l",memory.fread8(pc+1), opcode);
			hl = memory.fread8(pc+1);pc+=2;
			break;
		case 0x36: //LD HL *
			debugOpcode8("ld hl",memory.fread8(pc+1), opcode);
			hl = memory.fread8(pc+1);pc+=2;
			break;
		case 0x2A: //LD HL **
			debugOpcode16("ld hl (**)",memory.fread16(pc+1), opcode);
			hl=memory.fread16(pc+1);
			pc+=3;
			break;	
		case 0x22: //LD ** HL 
			debugOpcode16("ld (**) hl",memory.fread16(pc+1), opcode);
			memory.fwrite16(memory.fread16(pc+1),hl);
			pc+=3;
			break;
		case 0x32: //LD ** A 
			debugOpcode16("ld (**) a",memory.fread16(pc+1), opcode);
			memory.fwrite8(memory.fread16(pc+1),a);
			pc+=3;
			break;
		case 0x3A: //LD ** HL 
			debugOpcode8("ld a (**)",memory.fread16(pc+1), opcode);
			a=memory.fread8(memory.fread16(pc+1));
			pc+=3;
			break;
		//------------------------------------
		//STACK Instructions
		//------------------------------------
		case 0xF9:
			debugOpcode("ld sp,hl", opcode);
			sp=hl;
			pc++;
			break;
		case 0x31:
			debugOpcode16("ld sp,",memory.fread16(pc+1),opcode);
			sp = memory.fread16(pc+1);
			pc+=3;
			break;
		case 0x33:
			debugOpcode("inc sp", opcode);
			sp++;
			pc++;
			break;
		case 0x3B:
			debugOpcode("dec sp", opcode);
			sp--;
			pc++;
			break;
		//------------------------------------
		//CALL Instructions
		//------------------------------------
		case 0xCD:
			debugOpcode16("call ",memory.fread16(pc+1),opcode);
			push16(pc + 3);
			pc = memory.fread16(pc+1);
			break;
		case 0xCF:
			debugOpcode("rst 08h",opcode);
			push16(pc + 1);
			pc = 0x08;
			break;
		case 0xC7: //rst 00h
			debugOpcode("rst 00h",opcode);
			push16(pc + 1);
			pc=0x0;
			break;
		case 0xFF: //rst 38h
			debugOpcode("rst 38h",opcode);
			push16(pc + 1);
			pc=0x38;
			break;
		//------------------------------------
		//Logical Instructions
		//------------------------------------
		case 0xB0:
			debugOpcode("or c",opcode);
			a |= b;
			pc++;
			break;
		case 0xB1:
			debugOpcode("or c",opcode);
			a |= c;
			pc++;
			break;
		case 0xB2:
			debugOpcode("or c",opcode);
			a |= d;
			pc++;
			break;
		case 0xB3:
			debugOpcode("or c",opcode);
			a |= e;
			pc++;
			break;
		case 0xB4:
			debugOpcode("or c",opcode);
			a |= h;
			pc++;
			break;
		case 0xB5:
			debugOpcode("or c",opcode);
			a |= l;
			pc++;
			break;
		//------------------------------------
		//FLAGS + COMPARE Instructions
		//------------------------------------
		case 0xFE:
			debugOpcode8("cp *",memory.fread8(pc+1), opcode);
			temp= a;
			temp= temp - memory.fread8(pc+1);
			if(temp==0)
				flag_zero=true;
			else
				flag_zero=false;
			//TODO: Finish flags
			pc+=2;
			break;
		default:
			printf("0x%04X\t|0x%X\t|??? \t<-- Unsupported Instruction\n",pc,opcode);
			processOpcode(0x76);
	}
}
