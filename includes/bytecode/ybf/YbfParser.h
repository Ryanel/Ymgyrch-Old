#ifndef YBF_PARSER_H
#define YBF_PARSER_H
#include <string>
using namespace std;
class YbfParser
{
	private:
		string filepath;
		uint16_t a,b,c,d;
		uint8_t memory[255];
	public:
		int execute();
		int start();
		int stop();
		void loadInfo(string path);
		void
};

#endif
