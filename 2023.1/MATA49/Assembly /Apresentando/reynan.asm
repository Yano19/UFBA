section .data
    apresentando db 'Hello, my name is Reynan Paiva', 0; db fefine a variavel mensagem com uma cadeia de caracteres
    len equ $-apresentando
section .text
    global _start

_start:
    mov rax, 1; preparando o registrador para fazer uma chamada no sistema write
    mov rdi, 1; saida padrão
    mov rsi, apresentando
    mov rdx, len; leitura
    syscall

    mov rax, 60; identificador da chamada  sys_exit
    mov rdi, 0; o retorno sera zero, indicando sucesso
    syscall
