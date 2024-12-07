.code16
.text
.globl _start

_start:
    # Empurrando os parâmetros para a pilha
    movw $5, %ax           # primeiro número
    push %ax                # empurra para a pilha
    movw $3, %bx           # segundo número
    push %bx                # empurra para a pilha

    # Chama a subrotina de soma
    call _somar

    jmp loop_final          # fim do programa

# Subrotina que soma dois números passados pela pilha
_somar:
    pop %bx                 # retira o segundo número da pilha (em %bx)
    pop %ax                 # retira o primeiro número da pilha (em %ax)

    addw %bx, %ax           # soma os dois números
    call _imprimir_numero   # chama a função de impressão do número
    ret

# Função que imprime um número armazenado em %ax
_imprimir_numero:
    # Converte o número em %ax para caracteres e imprime
    movw %ax, %bx           # copia o número para %bx
    movb $0, %cl            # inicializa o contador de dígitos

    # Processa o número e imprime dígitos
imprimir_loop:
    xor %dx, %dx            # limpa %dx (necessário para a divisão)
    divb $10                # divide %bx por 10, resultado em %al, resto em %ah
    addb $'0', %al          # converte o dígito para o caractere ASCII
    movb %al, %dl           # move o dígito para %dl
    movb $0x0e, %ah         # modo de impressão de caractere
    int $0x10               # chama a interrupção para imprimir o caractere

    inc %cl                 # incrementa o contador de dígitos
    test %bx, %bx           # verifica se o número é zero
    jnz imprimir_loop       # se não for zero, continua o loop

    ret

# Finalizar programa
loop_final:
    hlt
    jmp loop_final

.org 510
.byte 0x55
.byte 0xaa
