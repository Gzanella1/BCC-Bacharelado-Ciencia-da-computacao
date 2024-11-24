.code16 			    
.text 				    
.globl _start

_start:             
    movw $100, %ax  # Valor a ser impresso
    movw $10, %bx     # Divisor (base 10)
    movw $0, %dx      # Reset do resto (será usado durante a divisão)

    call imprimir_ax  # Chama a função para imprimir AX
    jmp loop_final    # Loop para encerrar o programa após a impressão

imprimir_ax:
    movw %ax, %cx     # Salva o valor original de AX em CX

    # Dividimos o valor de AX por 10000 para extrair o primeiro dígito
    movw $10000, %bx  # Primeiro divisor
    call imprimir_digito
    
    # Depois por 1000, para o segundo dígito
    movw $1000, %bx   # Segundo divisor
    call imprimir_digito
    
    # E assim sucessivamente para 100, 10 e 1
    movw $100, %bx
    call imprimir_digito
    
    movw $10, %bx
    call imprimir_digito
    
    movw $1, %bx
    call imprimir_digito
    
    ret

imprimir_digito:
    # Divide AX pelo valor em BX
    xor %dx, %dx     # Limpa DX (resto)
    div %bx          # AX / BX -> quociente em AX, resto em DX
    addb $48, %al    # Converte o quociente (que está em AL) para o caractere ASCII

    # Imprime o dígito
    movb $0x0e, %ah  # Serviço de impressão de caractere
    int $0x10        # Interrupção de vídeo da BIOS para imprimir o caractere

    # Restaura o valor original para continuar a divisão
    movw %cx, %ax    # Restaura AX para o valor original armazenado em CX

    # Remove o dígito impresso (AX = AX % BX * 10)
    movw %dx, %ax    # Resto da divisão movido para AX
    ret

# Loop para manter o processador em halt
loop_final:
    hlt
    jmp loop_final

# Assinatura de boot MBR
. = _start + 510
.byte 0x55		        
.byte 0xaa		        
