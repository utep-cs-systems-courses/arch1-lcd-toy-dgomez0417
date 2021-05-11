	.arch msp430g2553 
	.p2align 1,0 /*power of two align, aliging eveything in paris*/

	.text
	.global chooseColor
chooseColor:
	sub &0x07e0, r12	   ; color - COLOR_GREEN  /*this is a note: r12 first parameter*/
	jnz notGreen               ; if not equal go to notGreen /*this is a note: JNE = jumo if not equal/zero*/
	mov &0xf114, r12    	   ; set COLOR_PURPLE as return value
	pop r0                     ; return

notGreen:
	sub &0xf114, r12     	   ; color - COLOR_PURPLE
	jnz notPurple              ; if not equal go to notPruple 
	mov &0xd708, r12  	   ; set COLOR_TURQUOISE as return value
	pop r0                     ; return

notPurple:
	mov &0x07e0, r12      	   ; set COLOR_GREEN as return value
	pop r0                     ; return
