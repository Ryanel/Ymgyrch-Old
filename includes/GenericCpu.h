#ifndef GENERIC_CPU_H
#define GENERIC_CPU_H
#include <GenericCpu.h>
class GenericCpu
{
	private:
		//Internal Functions

	public:
		void step();
		void reset();
		GenericCpu();
		~GenericCpu();
		bool running;
};

#endif
