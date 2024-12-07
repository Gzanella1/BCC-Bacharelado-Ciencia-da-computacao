.code16
.text
.globl _start


# http://www.gabrielececchetti.it/Teaching/CalcolatoriElettronici/Docs/i8086_instruction_set.pdf 
# https://4beginner.com/8086-Assembly-Language-INT-10h-Video-Interrupt
# https://www.stanislavs.org/helppc/int_10.html
# https://www.facom.ufu.br/~gustavo/OC1/Apresentacoes/Assembly.pdf
# int 10
# https://en.wikipedia.org/wiki/Intel_8086
# https://www.eng.auburn.edu/~sylee/ee2220/8086_instruction_set.html


_start:
     jmp _1


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
    # Coloca o valor 8 em %al
    movb $8, %al            
    movb $2, %bl            
    call multiplicar    
    # imprimir so para testar     
    call _imprimir_ax       
    call _imprimir_bx       
    call _imprimir_cx       
    call _imprimir_dx     
    
    jmp loop_final          

multiplicar:
    # aqui eu salvo o valor de AX (preserva o conteúdo original de AX)
    push %ax                
    # mult AL  por BL
    mul %bl                 
    movw %ax, %dx      
    # Restaura o valor original de AX     
    pop %ax                 
    ret                    



# Divida um número de 16 bits por outro de 8 bits.
_3:
    # 8 %ax (dividendo)
    movw $8, %ax          
    # 2 %bl (divisor)
    movb $2, %bl          
    # quociente em %al, resto em %ah
    div %bl               
    movb %al, %dl         
    call _imprimir_dx     
    jmp loop_final



# Realize operações lógicas (AND, OR, NOT, XOR) entre dois registradores.
_4:
    # aqui o eu escolho qual das operações chamar 
	call _or

	_and:
		movb $0xF0, %al      
		movb $0x0F, %bl      
		and %bl, %al         
		ret

	_or:
		movb $0xF0, %al     
		movb $0x0F, %bl    
		or %bl, %al         
		call _imprimir_ax
		ret
	
	_not:
		movb $0x0F, %al      
		not %al              
		ret

	_xor:
		movb $0xF0, %al      
		movb $0x0F, %bl      
		xor %bl, %al         
		ret




# Leia um valor de uma posição de memória e armazene em um registrador.
_5:
    # não consegui fazer 


# Escreva um valor em uma posição específica da memória.
_6:
    # não consegui fazer 


# Crie um array de números e calcule a soma de todos os elementos.
_7:
    # não consegui fazer 



# Controle de Fluxo:
# https://www.facom.ufu.br/~gustavo/OC1/Apresentacoes/Assembly.pdf     [pagina 52]
# Implemente um loop que conte de 1 a 10.
_8:
    movw $1, %ax        
    movw $20, %bx       

    loop_in:
        # imprima os valores de ax ( fiz isso de colocar na pilha pq meu imprimri modifica o ax e caga com todo o meu jump )
        push %ax            
        call _imprimir_ax 
        pop %ax            

        cmp %ax, %bx     
        # se ax e bx forem iguais pula para o loop final 
        je end_loop        

        inc %ax             
        jmp loop_in         

    end_loop:
        ret                

# Crie uma função que verifique se um número é par ou ímpar.
_9:
    movw $55, %ax    
    movw $2, %bx    
    
    #  eder disse que é para garantir que esta zerado 
    xorw %dx, %dx    
    # divide AX por BX, resto fica em DX
    divw %bx         
    cmpw $0, %dx     
    # se resto for zero, é par
    je _par          
    # se resto for diferente de zero, é ímpar
    jne _impar     
    
    jmp loop_final

    _par:
        movb $'p', %al   
        movb $0x0e, %ah     
        int $0x10           
        ret

    _impar:
        movb $'i', %al 
        movb $0x0e, %ah     
        int $0x10            
        ret



#  Utilize instruções de desvio condicional (JE, JNE, JG, JL) para tomar decisões em seu programa.
_10:
    movw $20, %ax         
    movw $20, %bx         

    # Compara AX com BX
    cmpw %bx, %ax      
    # se AX == BX  
    je _igual          
    # se AX != BX
    jnz _diferente       

    _igual:
        push %ax 
        movb $'I', %al       
        movb $0x0e, %ah      
        int $0x10             
        pop %ax
        # se eles forem iguais não tem motivos para ver se é maior ou menor
        jmp loop_final                 

    _diferente:
        # to usando o push aqui pq na hr de imprimir percebi que estava alterando o valor de ax 
        push %ax
        movb $'D', %al        
        movb $0x0e, %ah       
        int $0x10            
        pop %ax

        # Verifica se é maior ou menor
        cmpw %bx, %ax       
        # Se AX > BX, maior
        jg _maior              
        # Se AX < BX, menor
        jl _menor  

    _maior:   
        # to usando o push aqui pq na hr de imprimir percebi que estava alterando o valor de ax 
        push %ax
        movb $'G', %al       
        movb $0x0e, %ah     
        int $0x10             
        pop %ax
        jmp loop_final              

    _menor:
        push %ax
        movb $'L', %al        
        movb $0x0e, %ah       
        int $0x10            
        pop %ax



# Subrotinas:
# Crie uma subrotina para calcular o fatorial de um número.
_11:
    
    movw $4, %ax    
    call fatorial
    call _imprimir_ax
    jmp loop_final

    fatorial:
        # Verifica casos especiais
        cmpw $0, %ax
        je caso_zero
        cmpw $1, %ax
        je caso_um

        # Caso geral
        # pego o valor jogo na pilha, decremento jogo na pilha 
        pushw %ax       
        decw %ax        
        call fatorial   

        # tiro da pilha 
        popw %bx        
        mulw %bx        
        ret

    caso_zero:
    caso_um:
        movw $1, %ax    
        ret





# Implemente uma subrotina para ordenar um array de números.
_12:

# Utilize a pilha para passar parâmetros para subrotinas.
_13:



# Entrada e Saída:
# Leia um caractere do teclado e exiba-o na tela.
_14:
    movb $0x00, %ah
    int $0x16
    mov $0x0e, %ah
    int $0x10
    jmp loop_final



# Leia uma string do teclado e exiba-a em uma nova linha.
# não funciona o enter 
_15:
    call texto
    jmp loop_final

texto:
    movb $0x00, %ah
    int $0x16
    mov $0x0e, %ah
    int $0x10

    jmp texto




# Utilize a interrupção 21h para realizar operações de entrada e saída.
_16:






# Manipulação de Strings:

# Copie uma string de uma área da memória para outra.
_17:



# Compare duas strings para verificar se são iguais.
_18:


# Concatene duas strings.
_19:
























# Função para imprimir o valor de AX em formato decimal
_imprimir_ax:
    push %bx                # Salva o valor de BX na pilha
    push %cx                # Salva o valor de CX na pilha
    push %dx                # Salva o valor de DX na pilha

    movw %ax, %dx           # Copia o valor de AX para DX (valor a ser impresso)
    movw $10, %bx           # Divisor para conversão em decimal (base 10)
    xorw %cx, %cx           # Zera o contador de dígitos
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






# Finalizar programa
loop_final:
    hlt
    jmp loop_final


.org 510                 
.byte 0x55
.byte 0xaa








