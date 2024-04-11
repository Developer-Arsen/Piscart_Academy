extern printf
struc Test
    .a resd 1
    alignb 8
    .b resb 1
    ; .c resb 52
endstruc

section .data
    fm  db "%d", 0 
    fmt db "%s", 0
    testi
section .bss
    obj resb Test_size

section .text
    global main:

main: 
    push rsp
    mov rbp, rsp

    mov eax, 25
    mov dword[obj + Test.a], eax

    mov rax, 0
    mov rdi, fm
    mov rsi, Test_size
    call printf

    mov rsp, rbp
    pop rsp
    ret