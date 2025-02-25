
# burocracias 
.code16 			    
.text 				    
.globl _start

# https://4beginner.com/8086-Assembly-Language-INT-10h-Video-Interrupt
# https://www.stanislavs.org/helppc/int_10.html

# ponto de entrada do programa
_start: 

# estou movendo o valor do loop para o registrador cl
movb $80, %cl
loop_80:
    # sempre armazenamos o caractere a ser impresso em al 
    movb $'x', %al
    # o serviço que estou solicitando é o saida de teletipo, que sempre deve estar em AH 
    movb $0x0e, %ah
    # a interrupção que estou cham
    int  $0x10
    decb %cl
    jnz loop_80

movb $23, %cl
imprimir_sox:
    # sempre armazenamos o caractere a ser impresso em al 
    movb $'x', %al
    # o serviço que estou solicitando é o saida de teletipo, que sempre deve estar em AH 
    movb $0x0e, %ah
    # a interrupção que estou cham
    int  $0x10
    
    movb $78, %ch
    imprimir_t:
        # sempre armazenamos o caractere a ser impresso em al 
        movb $'-', %al
        # o serviço que estou solicitando é o saida de teletipo, que sempre deve estar em AH 
        movb $0x0e, %ah
        # a interrupção que estou cham
        int  $0x10
        decb %ch
        jnz imprimir_t
        
    # sempre armazenamos o caractere a ser impresso em al 
    movb $'x', %al
    # o serviço que estou solicitando é o saida de teletipo, que sempre deve estar em AH 
    movb $0x0e, %ah
    # a interrupção que estou cham
    int  $0x10
    
    decb %cl
    jnz imprimir_sox


# loop para manter o processador em estado de halt
loop_final:
    hlt
    jmp loop_final

# move o contador da posição atual no código (representado pelo .) para o byte 510
. = _start + 510

# assinatura de boot MBR
# pro programa ser reconhecido como boot MBR,
# é preciso que os bytes 510 e 511 tenham os valores 0x55 e 0xaa
.byte 0x55		        
.byte 0xaa		        



