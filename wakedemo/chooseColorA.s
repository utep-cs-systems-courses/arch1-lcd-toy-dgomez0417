	.arch msp430g2553 
	.p2align 1,0 /*power of two align, aliging eveything in paris*/

	.text
	.global chooseColor
chooseColor:
	cmp &COLOR_GREEN, r12	   ; color - COLOR_GREEN  /*this is a note: r12 first parameter*/
	jnz notGreen               ; if not equal go to notGreen /*this is a note: JNE = jumo if not equal/zero*/
	mov &COLOR_PURPLE, r12     ; set COLOR_PURPLE as return value
	pop r0                     ; return

notGreen:
	cmp &COLOR_PURPLE, r12     ; color - COLOR_PURPLE
	jnz notPurple              ; if not equal go to notPruple 
	mov &COLOR_TURQUOISE, r12  ; set COLOR_TURQUOISE as return value
	pop r0                     ; return

notPurple:
	mov &COLOR_GREEN, r12      ; set COLOR_GREEN as return value
	pop r0                     ; return