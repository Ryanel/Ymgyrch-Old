#ifndef YBF_PARSER_H
#define YBF_PARSER_H
#include <string>
using namespace std;
class SmtlCpu
{
	private:
		int pc;
		char a,b,c,d;
		char memory[255];
		char vmem[59];
		void processOpcode(char opcode);
	public:
		int execute(char opcode[],int num);
		int doOp(char opcode);
};

#endif
