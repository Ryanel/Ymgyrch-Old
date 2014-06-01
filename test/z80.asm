jp start
db "Hello z80 world!", 0
halt:
	halt
	jp halt
start:
	call halt