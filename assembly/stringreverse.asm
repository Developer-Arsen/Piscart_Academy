extern printf:
extern scanf:
section .data 
    fmn db "%d", 0, 0xa
    fms db "%s", 0
    arr dd 1,2,3,4,5,21
    strt db "hello", 0 
    size equ ($ - strt)
section .text
    global main:
main: 
    push rsp
    mov rbp, rsp

    sub rsp, 16
    mov r13, 0
loop: 
    cmp r13, (size / 2)
    jge end

    mov r8, 0
    mov r8, size
    sub r8, r13
    sub r8, 2

    mov rdx, 0
    mov dl, byte[strt + r13]
    mov byte[rbp-16], dl

    mov rdx, 0
    mov dl, byte[strt + r8]
    mov byte[rbp-8], dl

    mov byte[strt + r13], dl

    mov rdx, 0
    mov dl, byte[rbp-16]
    mov byte[strt + r8], dl

    
    inc r13
    jmp loop
   
end:

    mov rax, 0
    mov rdi, fms
    mov rsi, strt
    call printf

    add rsp, 16

    mov rbp,rsp
    pop rsp

    mov rax, 0
    mov rdi, 60
    syscall