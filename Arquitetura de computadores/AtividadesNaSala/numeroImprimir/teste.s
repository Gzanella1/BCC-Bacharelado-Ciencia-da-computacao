
# burocracias 
.code16 			    
.text 				    
.globl _start

# https://4beginner.com/8086-Assembly-Language-INT-10h-Video-Interrupt
# https://www.stanislavs.org/helppc/int_10.html

# int 10
# https://en.wikipedia.org/wiki/Intel_8086
# https://www.eng.auburn.edu/~sylee/ee2220/8086_instruction_set.html

# ld procura este rótulo _start como o ponto de entrada padrão de um programa
_start:             
    # move um byte para o registrador al, parte inferior do registrador ax, na AT&T 
    # registro de sintaxe é precedido pelo símbolo %, literais são precedidos 
    # por $ símbolo
    movb $'x' , %al     # caractere para imprimir
    # move um byte para registrar ah, parte superior do registro ax
    movb $0x0e, %ah     
    # A arquitetura do modelo IBM-PC AT/XT usa interrupção de software para
    # fornece alguns serviços, int 0x10 está relacionado a serviços de VÍDEO, 
    # serviços de BIOS
    int  $0x10          # bios service (interrupt) 
    movw $54321, %ax
    movw $10000, %bx
    movw $10, %cx
    movw $0, %dx
    call loop_divisao
    jmp loop_final
    


loop_divisao: 
    # compara se é zero0
    cmpw $0, %ax
    # jump se igual 
    je loop_divisaoEnd
    # ja ta definido o valor em ax que eu vou divididr por bx
    div %bx
    # 5 ja esta em ax 
    # 4321 esta em dx 0 
    addb $48, %al
    movb $0x0e, %ah
    int $0x10
    # eu quero dividir o 10000 por 10, div so atua em ax movendo 
    movw %bx, %ax 
    movw %cx, %bx
    # movendo 4321 para não perder parao resto da div acima  
    movw %dx, %cx
    # dividindo 10000 p 10
    div %bx
    # voltar os valores 
    movw %ax, %bx
    movw %cx, %ax
    movw $10, %cx
    movw $0, %dx
    jmp loop_divisao



loop_divisaoEnd:
    ret


loop_bla:
    hlt
    jmp loop_bla
    # movb %bh , %al     
    # add $48, %al 
    # movb $'x' , %al       # caractere para imprimir
    movb $0x0e, %ah     
    # serviços de BIOS
    int  $0x10      
    ret
    


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



