start:
	ld a,0ffh
	ld (8000h),a
	ld a,(8000h)
	cp 0ffh
	jp z,worked
	jp failed
	halt
worked:
	ld e, 0
	halt
failed:
	ld e, 255
	halt