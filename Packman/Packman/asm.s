
.extern sum
.global sum
.func sum
sum:
	sbi	PORTC, 0
	ret
.endfunc