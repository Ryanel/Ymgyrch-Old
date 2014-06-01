#include <GenericCpu.h>
#include <stdio.h>
using namespace std;
CHIP8Cpu::CHIP8Cpu() //Put init stuff here
{
	printf("PC\t|OP\t|Ins.\n");
	printf("--------|-------|-------\n");
	running=true;
	memory.fwrite8(0,1);
}
void CHIP8Cpu::step() //Called every frame
{
	processOpcode(memory.fread8(pc));
}
void CHIP8Cpu::reset() //Reset everything
{

}

void CHIP8Cpu::debugOpcode(string name, uint8_t opcode)
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
	}
}
