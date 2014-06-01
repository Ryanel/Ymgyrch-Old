#ifndef GENERIC_SYSTEM_H
#define GENERIC_SYSTEM_H
#include <GenericCpu.h>
#include <cstring>
#include <string>
using namespace std;
class GenericSystem
{
	private:
		//Internal Functions

	public:
		void step();
		void reset();
		GenericSystem(const string filename);
		~GenericSystem();
		virtual void run();
};

#endif
