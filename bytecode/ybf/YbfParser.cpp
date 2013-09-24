#include <bytecode/ybf/YbfParser.h>
#include <stdio.h>
int YbfParser::execute()
{
	printf("YBF: EXECUTE\n");
	return 0;
}
int YbfParser::start()
{
	printf("YBF: START\n");
	return 0;
}
int YbfParser::stop()
{
	printf("YBF: STOP\n");
	return 0;
}
void YbfParser::loadInfo(string path)
{
	printf("YBF: %s loaded\n",path.c_str());
}
