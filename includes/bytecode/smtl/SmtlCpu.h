#ifndef YBF_PARSER_H
#define YBF_PARSER_H
#include <string>
using namespace std;
class SmtlCpu
{
	private:
		int pc;
		unsigned char a,b,c,d;
		signed char s;
		char vmem[59];
		void processOpcode(char opcode);
	public:
		void step();
		int execute(char opcode[],int num);
		char memory[255];
		char bios[200];
		void executeBios(char *toload);
		void executeBiosInstruction(char op);
		int doOp(char opcode);
		bool isExecuting;
		SmtlCpu();
		bool isDebugging;
};

#endif
