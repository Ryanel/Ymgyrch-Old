#include <bytecode/smtl/SmtlCpu.h>
#include <stdio.h>
int SmtlCpu::doOp(char opcode)
{
    processOpcode(opcode);
}
int SmtlCpu::execute(char opcode[],int num)
{
    printf("Unimplemented: execution\n");
}
void SmtlCpu::processOpcode(char opcode)
{
    printf("Unimplemented: opcode processing\n");
}