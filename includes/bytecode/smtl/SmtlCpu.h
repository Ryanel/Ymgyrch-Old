#ifndef YBF_PARSER_H
#define YBF_PARSER_H
#include <string>
using namespace std;
class SmtlCpu
{
	private:
		int pc;
		char a,b,c,d;

		char vmem[59];
		void processOpcode(char opcode);
	public:
		void step();
		int execute(char opcode[],int num);
		char memory[255];
		int doOp(char opcode);
		bool isExecuting;
		SmtlCpu();
};

#endif
