section .data
    arr dd 1,2,3,4,5
    decimal db "%d",0
    size equ ($-arr) / 4
section .rodata
section .text
    extern printf
    global main:

main: 
    push rbp
    mov rbp, rsp
    sub rsp, 16

    mov dword[rbp-8], size
    mov rbx, 0
loop_: 
    cmp ebx, dword[rbp-8]
    jae end

    mov rax, 0
    mov rdi, decimal
    movsx rsi, dword[arr + rbx * 4]
    call printf

    inc rbx
    jmp loop_

end: 
    mov rsp, rbp
    pop rbp
    ret

