#ifndef YBF_PARSER_H
#define YBF_PARSER_H
#include <string>
using namespace std;
class YbfParser
{
	private:
		string filepath;
		unsigned short a,b,c,d;
		unsigned short memory[255];
	public:
		int execute();
		int start();
		int stop();
		void loadInfo(string path);
};

#endif
