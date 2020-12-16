	.data
text:	.string "Hello World\n"
	.align 2

	.text
	.global main

main:
	stmfd sp!, {lr} @prologue
	ldr r0, =text
	bl printf
	mov r0, #0x0
	ldmfd sp!, {lr} @epilogue
	mov pc, lr @return
