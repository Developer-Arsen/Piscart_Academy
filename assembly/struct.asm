extern printf
struc MyStruct
    .integer resd 1    ; Reserve space for a 32-bit integer
    .byte    resb 1    ; Reserve space for a byte
    .size    equ  $ - MyStruct  ; Calculate the total size of the struct
endstruc

section .data
    fm  db "%d", 0 
    fmt fb "%s", 0
    ; myStruct:
    ;     a dd 0,
    ;     b db 0,
    ;     align 3
    ;     c dq 0

section .bss
    obj resb MyStruct_size

section .text
    global main:

main: 
    push rbp
    mov, rsp, rbp

    mov rax, 0
    mov rsi, fm
    movsx rdi, MyStruct_size
    call printf

    mov rsp, rbp
    pop rbp    