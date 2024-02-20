; 1darr.asm
section .data
    decimal db "%d",10
    arr dd 1,2,3,4,5
    size equ $-arr
section .bss
    ; arr resd 5
section .text
    extern printf;
    extern scanf;

    global get_arr_count;
    global print_arr;
    global scan_arr;
    global main:

get_arr_count: 
        enter 0,0

        mov rax, size
        mov r8 , 4
        mov rdx, 0
        div r8 
        mov r8, rax ; elements counts 

        leave
        ret

print_arr: 
    enter 0,0

loop_:
        mov rcx, 0
        cmp rcx, r8
        je scan_arr_end

        mov rax, 0
        mov rdi, decimal
        mov rsi, r8
        call printf

        inc rcx
        jmp loop_
scan_arr_end:
        leave
        ret
main: 
    enter 0,0

    call get_arr_count
    call print_arr

end:
    leave 
    ret

; scan_arr: 
;     enter 0,0

;     cmp rcx, 4
;     je scan_arr_end

;     ; mov rax, rcx
;     ; mov r8, 4,
;     ; mul r8
;     ; mov r8, rax

;     mov rax, 0
;     mov rdi, decimal
;     ; movsx rsi, dword[arr+r8]
;     movsx rsi, dword[arr]
;     call scanf
;     dec rcx

;     leave
;     ret
    