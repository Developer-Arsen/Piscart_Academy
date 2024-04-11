extern printf:
extern scanf:
section .data 
    fmn db "%d", 0xa
    arr dd 1,2,3,4,5,21
    size equ ($ - arr) / 4
section .rodata
    ; size equ 5
section .bss
    sum resw 1
section .text
    global main:
main: 
    push rsp
    mov rbp, rsp


    sub rsp, 16
    mov edx, [arr]
    mov dword[rbp-8], edx

    mov r13, 0
loop: 
    cmp r13, size
    je end

    mov edx, [arr + r13 * 4]
    cmp dword[rbp-8], edx
    jge next
   
    mov dword[rbp-8], edx
next:   
    inc r13
    jmp loop
end:

    mov rax, 0
    mov rdi, fmn
    mov esi, dword[rbp-8]
    call printf

    add rsp, 16

    mov rbp,rsp
    pop rsp

    mov rax, 0
    mov rdi, 60
    syscall