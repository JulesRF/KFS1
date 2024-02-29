bits 32

section .multiboot
        dd 0x1BADB002               ; Magic number for bootloader
        dd 0x0                      ; Flags
        dd - (0x1BADB002 + 0x0)     ; Checksum

section .text
global start
extern main                         ; Main

start:
    cli                             ; Clear interrupts
    sti
    xor ebp, ebp
    call main                       ; Main call
    jmp .1
.1:
    hlt
    ; hlt                           ; Halt CPU
