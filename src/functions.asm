section .text
    global f1
    global f2
    global f3

f1:
    push ebp
    mov ebp, esp
    sub esp, 4

    mov dword[esp], __float32__(3.0)
    fld dword[esp]

    mov dword[esp], __float32__(0.5)
    fld dword[esp]

    mov eax, dword[ebp + 8]
    mov dword[esp], eax
    fld dword[esp]

    mov dword[esp], __float32__(1.0)
    fld dword[esp]

    faddp
    fdivp

    mov dword[esp], __float32__(1.0)
    fld dword[esp]

    faddp
    fmulp

    add esp, 4
    pop ebp
    ret

f2:
    push ebp
    mov ebp, esp
    sub esp, 4

    mov dword[esp], __float32__(2.5)
    fld dword[esp]

    mov eax, dword[ebp + 8]
    mov dword[esp], eax
    fld dword[esp]

    fmulp

    mov dword[esp], __float32__(9.5)
    fld dword[esp]

    fsubp

    add esp, 4
    pop ebp
    ret

f3:
    push ebp
    mov ebp, esp
    sub esp, 4

    mov dword[esp], __float32__(5.0)
    fld dword[esp]

    mov eax, dword[ebp + 8]
    mov dword[esp], eax
    fld dword[esp]

    fdivp

    add esp, 4
    pop ebp
    ret

