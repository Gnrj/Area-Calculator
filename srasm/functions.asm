section .text
global f1
global f2
global f3

f1: ;exp(-x)+3
    push ebp
    mov ebp, esp
    sub esp, 4

    finit
    fld dword[ebp+8]
    fchs ;-x
    fldl2e ;log2e
    fmulp
    fist dword[ebp-4]
    fild dword[ebp-4] ;st0 - целая часть, st1 - xlog2e
    fsub st1, st0 ;st1 = {xlog2e}
    fld1 ;
    fscale ;st0 - 2^[xlog2e], st1 - [xlog2e], st2 - {xlog2e}
    fxch st1 
    fistp dword[ebp-4]
    fxch ;st0 = {xlog2e}, st1 - 2^[xlog2e]
    f2xm1
    fld1
    faddp st1, st0 ;st1 - 2^[xlog2e], st0 = 2^{xlog2e}
    fmul st0, st1
    fxch
    fstp dword[ebp-4]
    fld1
    fld1
    fld1
    faddp
    faddp
    faddp

    mov esp, ebp
    pop ebp
    ret

f2: ;2x-2
    push ebp
    mov ebp, esp
    
    finit
    fld dword[ebp+8] ;st0 = x
    fld1
    fsubp ;st0 = x-1
    fld1
    fld1
    faddp ;st0 = 2, st1 = x-1
    fmulp ;2x-2

    mov esp, ebp
    pop ebp
    ret

f3: ;1/x
    push ebp
    mov ebp, esp
    
    finit
    fld1
    fld dword[ebp+8]
    fdivp

    mov esp, ebp
    pop ebp
    ret


