section .data
    fm db "%d", 0
section .bss
    buffer resb 256
section .text
    global main:
    extern printf

main:
    push rbp
    mov rbp, rsp

    mov rax, 0
    mov rdi, 0
    mov rsi, buffer
    mov rdx, 256
    syscall

    mov rdi, fm
    mov rsi, rax
    call printf

    mov rsp, rbp
    pop rbp

    ret
    
