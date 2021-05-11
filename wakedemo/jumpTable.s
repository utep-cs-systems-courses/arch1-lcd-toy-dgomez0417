	.arch msp430g2553
	.p2align 1,0
	.data

state:
	.byte 0
	.text

jt:	.word case0
	.word case1
	.word default
	.global allShape

allShape:
	cmp #4, &state		; state -4
	jc default		; jump if not borrowed

	mov &state, r12		; move state into r12
	add r12, r12		; add r12 to itself. indexing of jt; double of the state.


	mov jt(r12),r0		; move address from branch into r0(program counter); reference of *(jt+r12)

case0:
	call #makeDiamond	; calls the method
	add #1, &state		; add 1 to state
	jmp out			; break

case1:
	call #makeDiamond1	; calls the method
	add #1, &state		; add 1 to state
	jmp out			; break
	
default:
	mov #0, &state		; default, move r0 to state
	
out:
	pop r0			; pop into R0. From the stack to r0.
	
	
