#define HEY "Hello preprocessed assembly file [%d]!"
/*NOTA: the code has to be valid assembly! hence C functions will always be discarded and the assembler will complain!! */
    .data
fmt: .string HEY
    .align 2

    .text
    .global main

main:
    stmfd sp!, {lr}
    ldr r0, =fmt
    mov r1, #0x18
    bl printf
    mov r0, #0
    ldmfd sp!, {pc}