.code16
.text
.globl _start

message: .asciz "Valor: %d\n"    # Mensagem para imprimir

_start:
    jmp _3

# Some dois números de 16 bits e armazene o resultado em um terceiro.
_1:
    movw $5, %ax           # Primeiro número
    movw $2, %bx           # Segundo número
    call _sum              # Chama a função de soma
    jmp loop_final         # Salta para o fim

# Soma o conteúdo de AX e BX e armazena em DX
_sum:
    movw %ax, %dx          # Copia AX para DX
    addw %bx, %dx          # Adiciona BX a DX
    call _imprimir_dx      # Chama a função de impressão em decimal
    ret


# Multiplique dois números de 8 bits e armazene o resultado em um registrador de 16 bits.
_2:
	movb $8, %al
	movb $2, %bl
	call multiplicar 
	call _imprimir_dx # resposta 
	
	call _imprimir_bx
	call _imprimir_ax
	jmp loop_final

	multiplicar:
		push %ax         # Salva o valor de AX (preserva o conteúdo original de AX)
		mul %bl          # Multiplica AL (parte inferior de AX) por BL
		movw %ax, %dx    # Move o valor de AX (resultado da multiplicação) para DX
		pop %ax          # Restaura o valor original de AX
		ret              # Retorna da função

# Divida um número de 16 bits por outro de 8 bits.
_3:
    movw $203, %ax        # Coloca o valor 203 (0xCB) em %ax (dividendo)
    movb $4, %bl          # Coloca o valor 4 em %bl (divisor)
    div %bl               # Divide %ax por %bl, quociente em %al, resto em %ah
    movb %al, %dl         # Move o quociente para %dl (para imprimir)
    call _imprimir_dx     # Imprime o valor do quociente
    ret







# Função para imprimir o valor de AX em formato decimal
_imprimir_ax:
    push %ax        # Salva o valor original de AX
    push %bx        # Salva o valor original de BX
    push %cx        # Salva CX
    push %dx        # Salva DX

    movw %ax, %dx   # Copia o valor de AX para DX (valor a ser impresso)
    movw $10, %bx   # Divisor para conversão em decimal (base 10)
    xorw %cx, %cx   # Zera o contador de dígitos


_imprimir_bx:
    push %ax        # Salva o valor original de AX
    push %bx        # Salva o valor original de BX
    push %cx        # Salva o valor original de CX
    push %dx        # Salva DX

    movw %bx, %dx   # Copia o valor de BX para DX (valor a ser impresso)
    movw $10, %bx   # Divisor para conversão em decimal (base 10)
    xorw %cx, %cx   # Zera o contador de dígitos

# Função para imprimir o valor de CX em formato decimal
_imprimir_cx:
    push %ax        # Salva o valor original de AX
    push %bx        # Salva o valor original de BX
    push %cx        # Salva o valor original de CX
    push %dx        # Salva DX

    movw %cx, %dx   # Copia o valor de CX para DX (valor a ser impresso)
    movw $10, %bx   # Divisor para conversão em decimal (base 10)
    xorw %cx, %cx   # Zera o contador de dígitos


# Função para imprimir o valor de DX em formato decimal
_imprimir_dx:
    push %ax        # Salva o valor original de AX
    push %bx        # Salva o valor original de BX
    push %cx        # Salva o valor original de CX
    push %dx        # Salva DX

    movw %dx, %ax   # Copia o valor de DX para AX (valor a ser impresso)
    movw $10, %bx   # Divisor para conversão em decimal (base 10)
    xorw %cx, %cx   # Zera o contador de dígitos


decimal_loop:
    xorw %dx, %dx   # Zera o valor de DX
    divw %bx        # Divide AX por 10, o resto vai para DX
    addw $48, %dx   # Converte o resto para o caractere correspondente ('0'-'9')
    push %dx        # Armazena o caractere na pilha
    inc %cx         # Incrementa o contador de dígitos
    testw %ax, %ax  # Verifica se o quociente é 0
    jnz decimal_loop # Se não for 0, continua dividindo

print_digits:
    pop %dx         # Restaura o próximo dígito da pilha
    movb %dl, %al   # Move o caractere para AL (necessário para int 0x10)
    movb $0x0E, %ah # Função de exibição de caractere (teletipo BIOS)
    int $0x10       # Chama a interrupção de vídeo
    dec %cx         # Decrementa o contador de dígitos
    jnz print_digits # Se ainda há dígitos, continua imprimindo

    pop %dx         # Restaura DX
    pop %cx         # Restaura CX
    pop %bx         # Restaura BX
    pop %ax         # Restaura AX
    ret

loop_final:
    hlt                    # Halta o sistema (espera por reinicialização)
    jmp loop_final         # Loop infinito

# Preenche o setor de boot com 0x55AA
.org 510                   # Garante que o código termine no offset 510
.byte 0x55
.byte 0xaa

