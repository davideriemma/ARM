    .data
fmt_000_000: .string "%d\t"
fmt_001_000: .string "\n"
    .align 4

    .text
    .global det
    .global print_matrix

print_matrix:
    stmfd sp!, {r4-r11, lr}
    mov r4, r0
    mov r5, r1 @riga
    mov r6, r2 @colonna
    mov r7, #0x0 @int i = 0
for_000:
    cmp r7, r6 @ i < colonna
    beq end_for_000
    mov r8, #0x0 @int y = 0 || L'inizializzazione del contatore del for va fatta subito prima del suo label, così ogni volta che il for viene eseguito, viene rieffettuata l'inizializzazione
for_001:
    cmp r8, r5 @ y < riga
    beq end_for_001
    ldr r0, =fmt_000_000
    @TBD: addressing mode per accedere agli elementi della matrice
    bl printf
    add r8, #0x01
    b for_001
end_for_001:
    ldr r0, =fmt_001_000
    bl printf
    add r7, #0x01  @l'incremento va invece fatto prima dell'istruzione di branch all'inizio del codice del for
    b for_000
end_for_000:
    ldmfd sp!, {r4-r11,pc}


det:
    stmfd sp!, {r4-r11, lr} @prologue  
    mov r4, r0 @save the pointer to the matrix
    mov r5, r1 @save the row size of the matrix
    mov r6, r2 @save the columns size
    @calcola il determinante
    ldmfd sp!, {r4-r11, pc} @epilogue
