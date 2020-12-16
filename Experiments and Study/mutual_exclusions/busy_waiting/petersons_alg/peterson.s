	.bss
turn:	.skip 4 @the int turn variable
flag:	.skip 8 @the flag[] array
	.data

	.text
	.global increment_by_1
	.global increment_by_2

increment_by_1:
	stmfd sp!, {r4-r11, lr} @prologue
	ldr r4, #0x01 @initialize the counter of the wasted iterations
	ldr r5, #0x00 @initialize the counter in the for cycle
for:	cmp r5, #0x03
	bge endfor

	@beginning of the peterson's algorithm
	ldr r6, =flag @carica in registro l'indirizzo del vettore
	ldr r8, [r6] @ottieni flag[0]
	ldr r8, #0x01 @flag[0] = true
	str r8, [r6] @ /// 
	ldr r7, =turn @carica in registro l'indirizzo della variabile turn
	ldr r9, #0x01 @ turn = 1
	str r9, [r7] @ ///
while:	ldr r10, [r6, #0x04] @carica flag[1] in registro
	ldr r9, [r7] @carica turn in registro
	ands r11, r10, r9 @ while(flag[1] && turn == 1)
	bne endwhile 
	add r4, r4, #0x01 @incrementa il numero dei cicli buttati
	@busy waiting
	b while
endwhile: 
	@begin critical section
	ldr r11, [r0] @accede alla memoria condivisa
	add r11, r11, #0x01 @incrementa la memoria condivisa
	str r11, [r0] @stores the resul back in memory
	@end of critical section
	@set flag[0] to false
	sub r8, r8, 0x01 @r8 da 1 passa a 0
	str r8, [r6] @store the result in flag[0]
	@continue of the for
	add r5, r5, # 0x1 @performs the increment
	b for
endfor:		
	ldmfd sp!, {r4-r11, lr} @epilogue
	mov r0, r4 @return the number of iteration spent waiting for the mutex
	mov pc, lr @return to main

increment_by_2:
	stmfd sp!, {r4-r11, lr} @prologue
	ldr r4, #0x01 @initialize the counter of the wasted iterations
	ldr r5, #0x00 @initialize the counter in the for cycle
for:	cmp r5, #0x02
	bge endfor

	@beginning of the peterson's algorithm
	ldr r6, =flag @carica in registro l'indirizzo del vettore
	ldr r8, [r6] @ottieni flag[0]
	ldr r8, #0x01 @flag[0] = true
	str r8, [r6] @ /// 
	ldr r7, =turn @carica in registro l'indirizzo della variabile turn
	ldr r9, #0x01 @ turn = 1
	str r9, [r7] @ ///
while:	ldr r10, [r6, #0x04] @carica flag[1] in registro
	ldr r9, [r7] @carica turn in registro
	ands r11, r10, r9 @ while(flag[1] && turn == 1)
	bne endwhile 
	add r4, r4, #0x01 @incrementa il numero dei cicli buttati
	@busy waiting
	b while
endwhile: 
	@begin critical section
	ldr r11, [r0] @accede alla memoria condivisa
	add r11, r11, #0x02 @incrementa la memoria condivisa
	str r11, [r0] @stores the resul back in memory
	@end of critical section
	@set flag[0] to false
	sub r8, r8, 0x01 @r8 da 1 passa a 0
	str r8, [r6] @store the result in flag[0]
	@continue of the for
	add r5, r5, # 0x1 @performs the increment
	b for
endfor:		
	ldmfd sp!, {r4-r11, lr} @epilogue
	mov r0, r4 @return the number of iteration spent waiting for the mutex
	mov pc, lr @return to main	
