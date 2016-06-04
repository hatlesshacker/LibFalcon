GLOBAL __get_cpuvendor

__get_cpuvendor:
    push    ebp
    mov     ebp, esp

    mov     eax, 0

    cpuid

    mov     eax, ebx

    mov     esp, ebp
    pop     ebp
    ret
