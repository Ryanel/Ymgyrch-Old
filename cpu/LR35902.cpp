#include <LR35902.h>
#include <LR35902Memory.h>
using namespace std;
LR35902Cpu::LR35902Cpu()
{

}
void LR35902Cpu::step()
{
	
}
void LR35902Cpu::reset()
{

		a=0;
		b=0;
		c=0;
		d=0;
		e=0;
		h=0;
		l=0;
		f=0; 
		pc=0;
		sp=0;
		m=0;
		t=0;
}