    .data
fmt_glorious_bitch: .string "I'm executing before main(), bitch!\n"
    .align 2
fmt_print_digit: .string "%d "
    .align 2

    .section .init
    bl shitty_man
    .align 2

    .text
    .global print_array
    .global sum_array
    .global shitty_man

shitty_man:
    stmfd sp!, {r4-r11, lr} @prologue
    ldr r0, =fmt_glorious_bitch @devo aspettarmi che i parametri tra r0 e r3 non siano mantenuti TRA LE CHIAMATE DI FUNZIONE, il 
                                @ ctx switch del sistema operativo li lascia invariati! Non devo preoccuparmi se, in un ctx switch, 
                                @ i valori in r0-r3 vengono sovarascritti
    bl printf @print
    ldmfd sp!, {r4-r11, pc} @epilogue and exit

@DEBUGGARE
print_array:
    /**
    * void print_array(int * array, size_t size)
    *
    * i won't save arguments on the stack, to improve performance, as it is a RISC architecture
    * r4: address of the array
    * r5: size of the array
     */
    stmfd sp!, {r4-r11, lr} @prologue
    mov r4, r0 @save the arguments
    mov r5, r1
    mov r6, #0x00 @ int i = 0
for_print_array:
    cmp r6, r5
    beq end_for_print_array
    ldr r7, [r4, r6, lsl #2] @access the array value, method using the counter: scaled register offset
    @ldr r7, [r4, #4]! @method using a constant: immediate offset pre indexed, the counter is never touched
    ldr r0, =fmt_print_digit @ fmt first argument
    mov r1, r7 @elements to the placeholder %d
    bl printf
if_print_array:
    cmp r6, #4
    bne end_if_print_array
    mov r0, #0x0A @ newline '\n'
    bl putchar @ print newline
end_if_print_array:
    add r6, r6, #0x01 @++i
    b for_print_array
end_for_print_array:
    mov r0, #0x0A @ newline '\n'
    bl putchar @ print newline 
    ldmfd sp!, {r4-r11, pc} @epliogue

sum_array:

    /**
        int sum_array(const int * array, size_t size)
        * r4: address of the array
        * r5: size of the array
     */

    stmfd sp!, {r4-r11, lr} @ prologo
    mov r4, r0
    mov r5, r1
    mov r6, #0x00 @nt i = 0
    mov r7, r6 @int sum = 0
for_sum_array:
    cmp r6, r5
    beq end_for_sum_array
    ldr r8, [r4, r6, lsl #2] @ register offset
    adc r7, r7, r8 @ sum += array[i]
    add r6, r6, #0x01 @ ++i
    b for_sum_array
end_for_sum_array:
    mov r0, r7 @return sum
    ldmfd sp!, {r4-r11, pc} @ epilogue

    .align 2
