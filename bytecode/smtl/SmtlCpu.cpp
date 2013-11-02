#include <bytecode/smtl/SmtlCpu.h>
#include <stdio.h>

SmtlCpu::SmtlCpu()
{
	isExecuting=true;
	isDebugging=false;
	pc=0;
	int mi=0;
	while(mi!=SMTL_CPU_MEM)
	{
		memory[mi]=0;
		mi++;
	}
	int vmi=0;
	while(vmi!=SMTL_CPU_VMEM)
	{
		vmem[vmi]=0;
		vmi++;
	}
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
		i++;
	}
}

void SmtlCpu::step()
{
	processOpcode(memory[pc]);
}

void SmtlCpu::executeBios(const char* toload)
{
	//TODO:Populate the BIOS, hardcoded for now
	memory[0]=4;
	memory[1]=4;
	memory[2]=0x9;
	memory[3]=0;
	memory[4]=4;
	memory[5]=0xA;
	memory[6]=0;
	memory[7]=0x64;
	memory[8]=0xB;
	memory[9]=0x1;
	memory[10]=0x64;
}

void SmtlCpu::processOpcode(char opcode)
{
	switch(opcode)
	{
		case 0x0: //HALT
			printf("hlt\n");
			if(isDebugging)
			{
				printf("=Registers===\n");
				printf("A -> 0x%X\tB -> 0x%X\tC -> 0x%X\tD -> 0x%X\tS -> 0x%X \n",a,b,c,d,s);
				printf("PC-> 0x%d\t\n",pc);
				printf("=Memory======\n");
				int mi=0;
				while(mi!=SMTL_CPU_MEM)
				{
					printf("%d\t",memory[mi]);
					mi++;
				}
				printf("\n");
				printf("=VMemory=====\n");
				int vmi=0;
				while(vmi!=SMTL_CPU_VMEM)
				{
					printf("%c",vmem[vmi]);
					vmi++;
				}
				printf("\n");
			}
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
		case 0x3: //BIOS
			printf("bios 0x%X\n",memory[pc+1]);
			break;
		case 0x4: //SET A
			printf("set A -> 0x%X\n",memory[pc+1]);
			a=memory[pc+1];
			pc+=2;
			break;
		case 0x5: //SET B
			printf("set B -> 0x%X\n",memory[pc+1]);
			b=memory[pc+1];
			pc+=2;
			break;
		case 0x6: //SET C
			printf("set C -> 0x%X\n",memory[pc+1]);
			c=memory[pc+1];
			pc+=2;
			break;
		case 0x7: //SET D
			printf("set D -> 0x%X\n",memory[pc+1]);
			d=memory[pc+1];
			pc+=2;
			break;
		case 0x8: //SET S
			printf("set S -> 0x%X\n",memory[pc+1]);
			s=memory[pc+1];
			pc+=2;
			break;
		case 0x9: //INC REGESTER from Memory
			switch(memory[pc+1])
			{
				case 0x0:
					printf("inc A (0x%X) <++ 0x%X\n",a,memory[pc+2]);
					a=a+memory[pc+2];
					break;
				case 0x1:
					printf("inc B (0x%X) <++ 0x%X\n",b,memory[pc+2]);
					b=b+memory[pc+2];
					break;
				case 0x2:
					printf("inc C (0x%X) <++ 0x%X\n",c,memory[pc+2]);
					c=c+memory[pc+2];
					break;
				case 0x3:
					printf("inc D (0x%X) <++ 0x%X\n",d,memory[pc+2]);
					d=d+memory[pc+2];
					break;
				case 0x4:
					printf("inc S (0x%X) <++ 0x%X\n",s,memory[pc+2]);
					s=s+memory[pc+2];
					break;
				default:
					printf("[!]inc unkn (unkn) <++ 0x%X\n",memory[pc+2]);
					break;
			}
			pc+=3;
			break;
		case 0xA: //SET Memory from Register
			switch(memory[pc+1])
			{
				case 0x0:
					printf("set A (0x%X) --> 0x%X\n",a,memory[pc+2]);
					memory[memory[pc+2]]=a;
					break;
				case 0x1:
					printf("set B (0x%X) --> 0x%X\n",b,memory[pc+2]);
					memory[memory[pc+2]]=b;
					break;
				case 0x2:
					printf("set C (0x%X) --> 0x%X\n",c,memory[pc+2]);
					memory[memory[pc+2]]=c;
					break;
				case 0x3:
					printf("set D (0x%X) --> 0x%X\n",d,memory[pc+2]);
					memory[memory[pc+2]]=d;
					break;
				case 0x4:
					printf("set S (0x%X) --> 0x%X\n",s,memory[pc+2]);
					memory[memory[pc+2]]=s;
					break;
				default:
					printf("[!]inc unkn (unkn) <++ 0x%X\n",memory[pc+2]);
					break;
			}
			pc+=3;
			break;
		case 0xB: //SET Register from pointer
			switch(memory[pc+1])
			{
				case 0x0:
					printf("set A (0x%X) <-- 0x%X\n",a,memory[pc+2]);
					a=memory[memory[pc+2]];
					break;
				case 0x1:
					printf("set B (0x%X) <-- 0x%X\n",b,memory[pc+2]);
					b=memory[memory[pc+2]];
					break;
				case 0x2:
					printf("set C (0x%X) <-- 0x%X\n",c,memory[pc+2]);
					c=memory[memory[pc+2]];
					break;
				case 0x3:
					printf("set D (0x%X) <-- 0x%X\n",d,memory[pc+2]);
					d=memory[memory[pc+2]];
					break;
				case 0x4:
					printf("set S (0x%X) <-- 0x%X\n",s,memory[pc+2]);
					s=memory[memory[pc+2]];
					break;
				default:
					printf("[!]set unkn (unkn) <++ 0x%X\n",memory[pc+2]);
					break;
			}
			pc+=3;
			break;
		default:
			printf("[pc 0x%X]:unkn\n",pc);
			pc++;
	}
}
