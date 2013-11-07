Ymgyrch (Expedition)
=======

A Virtual Machine and/or emulation platform that supports different architectures and byte code formats.

Planned supported formats
-----------------

### Ymgyrch bytecode file (.ybf)
The native bytecode format. Light and quick, avalable under bytecode/ybf.

Ymgyrch will also contain the assembler / compiler for ymgyrch.


### Self Modifing Test Format (.smtl)
Another native bytecode format. Developed as an experiment for self modifing code.

### Android Dalvik Executable (.dex)
A executable for the Android Dalvik Virutal Machiene. Also light and quick.
Ymgyrch will attempt emulate Dalvik as close as possible.
Not now; of course, this is only a goal.

### Java Bytecode (.class)
Emulation of a java virtual machiene. Might be really fun. Not implemented.

### Arcitecture Specific Executables (.bin, .elf)

Emulation of a normal executable running under any (suppported) architecture.

Planned Architecutres
-----------------
* Z80 <-- In progress
* LR35902 <-- Depends on Z80
* 8086
* 8080
* ARM

Planned Systems
-----------------
* IBM PC
* Generic x86-16 -> x86-32 systems
* Generic ARM
* ZX Spectrum
* Gameboy (Not color)