#include <bytecode/smtl/SmtlCpu.h>
#include <stdio.h>

SmtlCpu::SmtlCpu()
{
	isExecuting=true;
	pc=0;
}
int SmtlCpu::doOp(char opcode)
{
    processOpcode(opcode);
}
int SmtlCpu::execute(char opcode[],int num)
{
	int i=0;
	while(i!=num)
	{
		processOpcode(opcode[i]);
	}
}

void SmtlCpu::step()
{
    processOpcode(memory[pc]);
}

void SmtlCpu::processOpcode(char opcode)
{
    switch(opcode)
    {
    	case 0x0: //HALT
    		printf("hlt\n");
    		isExecuting=false;
    		break;
    	case 0x1: //SET MEMORY
    		printf("set 0x%X -> 0x%X\n",memory[pc+1],memory[pc+2]);
    		memory[memory[pc+1]]=memory[pc+2];
    		pc=pc+3;
    		break;
    	case 0x2: //JMP
			printf("jmp 0x%X\n",memory[pc+1]);
			pc=memory[pc+1];
			break;
    	default:
    		printf("???\n");
    		pc++;
	}
}
