#ifndef SMTL_CPU_PARSER_H
#define SMTL_CPU_PARSER_H
#include <string>
using namespace std;
#define SMTL_CPU_VMEM 59
#define SMTL_CPU_MEM  255
#define SMTL_CPU_BIOS 200
class SmtlCpu
{
	private:
		int pc;
		unsigned char a,b,c,d;
		signed char s;
		char vmem[SMTL_CPU_VMEM];
		void processOpcode(char opcode);
	public:
		void step();
		int execute(char opcode[],int num);
		char memory[SMTL_CPU_MEM];
		char bios[SMTL_CPU_BIOS];
		void executeBios(const char* toload);
		void executeBiosInstruction(char op);
		int doOp(char opcode);
		bool isExecuting;
		SmtlCpu();
		bool isDebugging;
};

#endif
