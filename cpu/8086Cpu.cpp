#include <8086.h>
#include <8086Memory.h>
using namespace std;
void I8086Cpu::step()
{
	
}
void I8086Cpu::reset()
{
		ax		= 0; //Primary Accumulator
		bx		= 0; //Base, Accumulator
		cx		= 0; //Counter, Accumulator
		dx		= 0; //Accumulator, Misc
		sp		= 0; //Stack Pointer
		bp		= 0; //Base Pointer
		si		= 0; //Source Index
		di		= 0; //Destination Index
		cs		= 0; //Stack Pointer
		ds		= 0; //Base Pointer
		es		= 0; //Source Index
		ss		= 0; //Stack 
		ip		= 0; //Program Counter
		flags 	= 0;//Flags (----ODITSZ-A-P-C)
}