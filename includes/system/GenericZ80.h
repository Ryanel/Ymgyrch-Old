#ifndef GENERIC_Z80_H
#define GENERIC_Z80_H
#include <GenericSystem.h>
#include <Z80.h>
class GenericZ80: public GenericSystem {
	private:
		Z80Cpu * cpu;
	public:
		void run();
		GenericZ80(string filename);
};

#endif
