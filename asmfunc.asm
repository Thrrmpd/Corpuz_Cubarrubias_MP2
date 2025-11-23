section .data
    const1000 dd 1000.0
    const3600 dd 3600.0

section .text
global asmfunc
default rel

asmfunc:
    movsxd rcx, ecx
    test rcx, rcx
    jz done
    movss xmm3, [const1000]
    movss xmm4, [const3600]


processloop:
    movss xmm0, [rdx]
    movss xmm1, [rdx+4]
    movss xmm2, [rdx+8]
    subss xmm1, xmm0
    mulss xmm1, xmm3
    divss xmm1, xmm4
    divss xmm1, xmm2
    cvtss2si eax, xmm1

    mov [r8], eax
    add rdx, 12
    add r8, 4
    dec rcx
    jnz processloop

done:
    ret