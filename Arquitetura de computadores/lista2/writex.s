.code16
.text
.section .text
.global _start


# https://www.ee.hacettepe.edu.tr/~alkar/ELE336/ele336_2014_week5.pdf 


_start:
    call _letrafundoPintado
    jmp loop_final




_limparTelal:
 # AH = 06h função de rolagem para cima
    movb $0x06, %ah         
    movb $0x00, %al    
    # BH= 07h  passar atributo branco sobre preto   
    movb $0x07, %bh         
    # CH= 00h lin inicial
    movb $0x00, %ch  
    # CL= 00h Col inicial     
    movb $0x00, %cl         
    # DH= 24 lin final 
    movb $0xC8, %dh    
    # DL= 79  col final     
    movb $0xC8, %dl         

    int $0x10               
    ret      


_moverCursorPosicaoEspecifica:
    # p/ definir a posição do cursor
    # AH= 02h  função para posicionar o cursor
    movb $0x02, %ah         
    movb $0x00, %bh    
    # DL= 25 coluna      
    movb $0x0a, %dl       
    # DH= 15 linha   
    movb $0x0f, %dh        

    int $0x10                
    ret

_escreverLetra:
    movb $0x0E, %ah         
    movb $'A', %al         
    # BL = 0x0F atributo: branco sobre preto
    movb $0x0F, %bl         
    int $0x10             
    ret

_letrafundoPintado:
    # AH = 09h Função de escrever caractere com atributo
    movb $0x09, %ah         
    movb $'B', %al        
    # BL = 0x1E texto amarelo e fundo azul
    movb $0x1E, %bl   
    # quanditdade de vezes que eu quero que excreva        
    mov $2, %cx             
    int $0x10                
    ret 


_alterarCorTela:
    movb $0x00, %ah       
     # AL = 0x03 modo de texto 80x25, 16 cores   
    movb $0x03, %al         
    int $0x10               
    # aqui preenche a tela com espaços e escrever caractere e atributo
    movb $0x09, %ah        
    movb $0x00, %bh   
    # AL= 0x20 ascii do espaço     
    movb $0x20, %al       
    # CX= 0x0800 quantidade de espaços 
    movw $0x0800, %cx       
    # algerar as cores 
    # movb $0x1F, %bl        # BL = 0x1F Branco intenso sobre fundo azul
    movb $0x4E, %bl          # Texto amarelo sobre fundo vermelho
    int $0x10                
    ret


loop_final:
    hlt                     
    jmp loop_final          

.org 510                   
.byte 0xaa
