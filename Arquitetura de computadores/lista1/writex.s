.code16
.text
.globl _start

# http://www.gabrielececchetti.it/Teaching/CalcolatoriElettronici/Docs/i8086_instruction_set.pdf 

# https://4beginner.com/8086-Assembly-Language-INT-10h-Video-Interrupt
# https://www.stanislavs.org/helppc/int_10.html

# int 10
# https://en.wikipedia.org/wiki/Intel_8086
# https://www.eng.auburn.edu/~sylee/ee2220/8086_instruction_set.html




message: .asciz "Valor: %d\n"    # Mensagem para imprimir

_start:
    jmp _5


# Some dois números de 16 bits e armazene o resultado em um terceiro.
_1:
    movw $5, %ax           
    movw $2, %bx           
    call _sum              
    jmp loop_final        

# Soma o conteúdo de AX e BX e armazena em DX
_sum:
    movw %ax, %dx          
    addw %bx, %dx         
    call _imprimir_dx      
    ret


# Multiplique dois números de 8 bits e armazene o resultado em um registrador de 16 bits.
_2:
    movb $8, %al            # Coloca o valor 8 em %al
    movb $2, %bl            
    call multiplicar        
    call _imprimir_ax       
    call _imprimir_bx       
    call _imprimir_cx       
    call _imprimir_dx       
    jmp loop_final          

multiplicar:
    push %ax                # Salva o valor de AX (preserva o conteúdo original de AX)
    mul %bl                 # Multiplica AL (parte inferior de AX) por BL
    movw %ax, %dx           # Move o valor de AX (resultado da multiplicação) para DX
    pop %ax                 # Restaura o valor original de AX
    ret                    


# Divida um número de 16 bits por outro de 8 bits.
_3:
    movw $8, %ax          # 8 %ax (dividendo)
    movb $2, %bl          # 2 %bl (divisor)
    div %bl               # quociente em %al, resto em %ah
    movb %al, %dl         
    call _imprimir_dx     
    ret



# Realize operações lógicas (AND, OR, NOT, XOR) entre dois registradores.
_4:
	call _or

	_and:
		movb $0xF0, %al      # AL = 11110000 (em binário)
		movb $0x0F, %bl      # BL = 00001111 (em binário)
		and %bl, %al         # AL = AL & BL => 11110000 & 00001111 = 00000000
		ret

	_or:
		movb $0xF0, %al      # AL = 11110000 (em binário)
		movb $0x0F, %bl      # BL = 00001111 (em binário)
		or %bl, %al          # AL = AL | BL => 11110000 | 00001111 = 11111111
		call _imprimir_ax
		ret
	
	_not:
		movb $0x0F, %al      # AL = 00001111 (em binário)
		not %al              # AL = ~AL => 11110000 (inverte os bits de AL)
		ret

	_xor:
		movb $0xF0, %al      # AL = 11110000 (em binário)
		movb $0x0F, %bl      # BL = 00001111 (em binário)
		xor %bl, %al         # AL = AL ^ BL => 11110000 ^ 00001111 = 11111111
		ret






# Manipulação de Memória: 

# Leia um valor de uma posição de memória e armazene em um registrador.


_5:
    # Endereço de memória onde o valor a ser lido está armazenado
    lea 0x1000, %ax      # Carrega o endereço de memória 0x1000 no registrador RAX (pode ser outro endereço)

    ; Lê o valor de memória e armazena no registrador AL
    movb %ax, %al            # Lê o byte armazenado no endereço apontado por RAX e coloca em AL
    
    ; Opcional: você pode adicionar um código para imprimir ou manipular o valor lido se necessário
    call _imprimir_ax            # Exemplo de chamada para imprimir o valor de AL
    
    ret



















































































# Função para imprimir o valor de AX em formato decimal
_imprimir_ax:
    push %bx                # Salva o valor de BX na pilha
    push %cx                # Salva o valor de CX na pilha
    push %dx                # Salva o valor de DX na pilha

    movw %ax, %dx           # Copia o valor de AX para DX (valor a ser impresso)
    movw $10, %bx           # Divisor para conversão em decimal (base 10)
    xorw %cx, %cx           # Zera o contador de dígitos

decimal_loop_ax:
    xorw %dx, %dx           # Zera o valor de DX
    divw %bx                # Divide AX por 10, o resto vai para DX
    addw $48, %dx           # Converte o resto para o caractere correspondente ('0'-'9')
    push %dx                # Armazena o caractere na pilha
    inc %cx                 # Incrementa o contador de dígitos
    testw %ax, %ax          # Verifica se o quociente é 0
    jnz decimal_loop_ax     # Se não for 0, continua dividindo

print_digits_ax:
    pop %dx                 # Restaura o próximo dígito da pilha
    movb %dl, %al           # Move o caractere para AL (necessário para int 0x10)
    movb $0x0E, %ah         # Função de exibição de caractere (teletipo BIOS)
    int $0x10               # Chama a interrupção de vídeo
    dec %cx                 # Decrementa o contador de dígitos
    jnz print_digits_ax     # Se ainda há dígitos, continua imprimindo

    pop %dx                 # Restaura DX
    pop %cx                 # Restaura CX
    pop %bx                 # Restaura BX
    ret                     # Retorna da função

# Função para imprimir o valor de BX em formato decimal
_imprimir_bx:
    push %ax                # Salva o valor de AX na pilha
    push %cx                # Salva o valor de CX na pilha
    push %dx                # Salva o valor de DX na pilha

    movw %bx, %ax           # Copia o valor de BX para AX (valor a ser impresso)
    movw $10, %bx           # Divisor para conversão em decimal (base 10)
    xorw %cx, %cx           # Zera o contador de dígitos

decimal_loop_bx:
    xorw %dx, %dx           # Zera o valor de DX
    divw %bx                # Divide AX por 10, o resto vai para DX
    addw $48, %dx           # Converte o resto para o caractere correspondente ('0'-'9')
    push %dx                # Armazena o caractere na pilha
    inc %cx                 # Incrementa o contador de dígitos
    testw %ax, %ax          # Verifica se o quociente é 0
    jnz decimal_loop_bx     # Se não for 0, continua dividindo

print_digits_bx:
    pop %dx                 # Restaura o próximo dígito da pilha
    movb %dl, %al           # Move o caractere para AL (necessário para int 0x10)
    movb $0x0E, %ah         # Função de exibição de caractere (teletipo BIOS)
    int $0x10               # Chama a interrupção de vídeo
    dec %cx                 # Decrementa o contador de dígitos
    jnz print_digits_bx     # Se ainda há dígitos, continua imprimindo

    pop %dx                 # Restaura DX
    pop %cx                 # Restaura CX
    pop %ax                 # Restaura AX
    ret                     # Retorna da função

# Função para imprimir o valor de CX em formato decimal
_imprimir_cx:
    push %ax                # Salva o valor de AX na pilha
    push %bx                # Salva o valor de BX na pilha
    push %dx                # Salva o valor de DX na pilha

    movw %cx, %ax           # Copia o valor de CX para AX (valor a ser impresso)
    movw $10, %bx           # Divisor para conversão em decimal (base 10)
    xorw %cx, %cx           # Zera o contador de dígitos

decimal_loop_cx:
    xorw %dx, %dx           # Zera o valor de DX
    divw %bx                # Divide AX por 10, o resto vai para DX
    addw $48, %dx           # Converte o resto para o caractere correspondente ('0'-'9')
    push %dx                # Armazena o caractere na pilha
    inc %cx                 # Incrementa o contador de dígitos
    testw %ax, %ax          # Verifica se o quociente é 0
    jnz decimal_loop_cx     # Se não for 0, continua dividindo

print_digits_cx:
    pop %dx                 # Restaura o próximo dígito da pilha
    movb %dl, %al           # Move o caractere para AL (necessário para int 0x10)
    movb $0x0E, %ah         # Função de exibição de caractere (teletipo BIOS)
    int $0x10               # Chama a interrupção de vídeo
    dec %cx                 # Decrementa o contador de dígitos
    jnz print_digits_cx     # Se ainda há dígitos, continua imprimindo

    pop %dx                 # Restaura DX
    pop %bx                 # Restaura BX
    pop %ax                 # Restaura AX
    ret                     # Retorna da função

# Função para imprimir o valor de DX em formato decimal
_imprimir_dx:
    push %bx                # Salva o valor de BX na pilha
    push %cx                # Salva o valor de CX na pilha

    movw %dx, %ax           # Copia o valor de DX para AX (valor a ser impresso)
    movw $10, %bx           # Divisor para conversão em decimal (base 10)
    xorw %cx, %cx           # Zera o contador de dígitos

decimal_loop_dx:
    xorw %dx, %dx           # Zera o valor de DX
    divw %bx                # Divide AX por 10, o resto vai para DX
    addw $48, %dx           # Converte o resto para o caractere correspondente ('0'-'9')
    push %dx                # Armazena o caractere na pilha
    inc %cx                 # Incrementa o contador de dígitos
    testw %ax, %ax          # Verifica se o quociente é 0
    jnz decimal_loop_dx     # Se não for 0, continua dividindo

print_digits_dx:
    pop %dx                 # Restaura o próximo dígito da pilha
    movb %dl, %al           # Move o caractere para AL (necessário para int 0x10)
    movb $0x0E, %ah         # Função de exibição de caractere (teletipo BIOS)
    int $0x10               # Chama a interrupção de vídeo
    dec %cx                 # Decrementa o contador de dígitos
    jnz print_digits_dx     # Se ainda há dígitos, continua imprimindo

    pop %cx                 # Restaura CX
    pop %bx                 # Restaura BX
    ret                     # Retorna da função

loop_final:
    hlt                     # Halta o sistema (finaliza o programa)
    jmp loop_final          # Loop infinito

# Preenche o setor de boot com 0x55AA
.org 510                   # Garante que o código termine no offset 510
.byte 0x55
.byte 0xaa
