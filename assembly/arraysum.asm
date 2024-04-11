extern printf:
extern scanf:
section .data 
    fmn db "%d", 0xa
    arr db 100,2,3,4,5
    size equ $ - arr
section .bss
    buffer resb 256
    sum resw 1

section .text
    global main:
main: 
    push rsp
    mov rbp, rsp

    mov dword[rbp-8], 0
    sub rsp, 16
    mov rcx, 0
loop: 
    cmp rcx, size
    je end

    mov ebx, dword[rbp-8]
    add bl, byte[arr + rcx]
    mov dword[rbp-8],  ebx   
    inc rcx

    jmp loop;
end: 
   
    mov rdi, fmn
    mov esi, dword[rbp-8]
    call printf

    add rsp, 16

    mov rbp,rsp
    pop rsp

    mov rax, 0
    mov rdi, 60
    syscall