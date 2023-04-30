section .data
    mensagem db 'Hello, World!'
    len equ $-mensagem
section .text
    global _start

_start:
    mov rax, 1 ;identificador da chama sys_write
    mov rdi, 1 ;saida padrao
    mov rsi, mensagem
    mov rdx, len
    syscall

    mov rax, 60; identificador da chamada  sys_exit
    mov rdi, 0; o retorno sera zero, indicando sucesso
    syscall
