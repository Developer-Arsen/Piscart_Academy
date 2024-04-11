extern printf:
extern scanf:
section .data 
    fmn db "%d", 0xa
section .rodata
    size equ 5
section .bss
    sum resw 1
section .text
    global main:
main: 
    push rsp
    mov rbp, rsp

    mov dword[rbp-8], 0
    sub rsp, 16

    mov r13, 0
    mov dword[rbp-16], 0
    mov dword[rbp-12], 1
    mov dword[rbp-8], 0
loop: 
    cmp r13, size
    je end

    mov r12d, dword[rbp-16] 
    mov r14d, dword[rbp-12]
    add r12d, r14d  

    mov dword[rbp-8], r12d 
    mov dword[rbp-16], r14d
    mov dword[rbp-12], r12d
    inc r13
    
    mov rax, 0
    mov rdi, fmn
    mov esi, dword[rbp-8]
    call printf
        
    jmp loop
end:
    add rsp, 16

    mov rbp,rsp
    pop rsp

    mov rax, 0
    mov rdi, 60
    syscall