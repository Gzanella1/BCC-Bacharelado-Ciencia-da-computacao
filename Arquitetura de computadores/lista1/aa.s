.code16
.text
.section .text
.global _start

_start:
    # 1. Limpar a tela (scroll up toda a tela com atributo padrão)
    movb $0x06, %ah          # AH = 06h (Função de rolagem para cima)
    movb $0x00, %al          # AL = 00 (Rolagem de toda a tela)
    movb $0x07, %bh          # BH = 07 (Atributo: Branco sobre preto)
    movb $0x00, %ch          # CH = 0 (Linha inicial)
    movb $0x00, %cl          # CL = 0 (Coluna inicial)
    movb $0x18, %dh          # DH = 24 (Linha final = 24)
    movb $0x4F, %dl          # DL = 79 (Coluna final = 79)
    int $0x10                # Chamar interrupção 10h para limpar a tela

    # 2. Mover o cursor para uma posição específica (linha 10, coluna 20)
    movb $0x02, %ah          # AH = 02h (Função de posicionar o cursor)
    movb $0x00, %bh          # BH = 0 (Página 0)
    movb $20, %dl            # DL = 20 (Coluna 20)
    movb $10, %dh            # DH = 10 (Linha 10)
    int $0x10                # Chamar interrupção 10h para mover o cursor

    # 3. Escrever um caractere na tela ('A')
    movb $0x0E, %ah          # AH = 0x0E (Função de exibir caractere TTY)
    movb $'A', %al           # AL = 'A' (Caractere a ser exibido)
    movb $0x0F, %bl          # BL = 0x0F (Atributo: Branco sobre preto)
    int $0x10                # Chamar interrupção 10h para escrever caractere

    # 4. Alterar  cor de fundo e de texto (Escrever caractere com atributo)
    movb $0x09, %ah          # AH = 09h (Função de escrever caractere com atributo)
    movb $'B', %al           # AL = 'B' (Caractere a ser exibido)
    movb $0x1E, %bl          # BL = 0x1E (Texto amarelo sobre fundo azul)
    mov $1, %cx             # CX = 1 (Escrever uma vez)
    int $0x10                # Chamar interrupção 10h para escrever caractere com cor

    # Esperar uma tecla para encerrar
    movb $0x00, %ah          # AH = 0x00 (Esperar entrada de tecla)
    int $0x16                # Chamar interrupção 16h para entrada do teclado

    # Finalizar programa (loop infinito)
hang:
    jmp hang                 # Loop infinito para encerrar o programa






_moverCursorPosicaoEspecifica:
    # Definir a posição do cursor
    movb $0x02, %ah          # AH = 02h (Função para posicionar o cursor)
    movb $0x00, %bh          # BH = 0 (Página de vídeo 0)
    movb $0x0a, %dl          # DL = 25 (Coluna 25 em hexadecimal é 0x19)
    movb $0x0f, %dh          # DH = 15 (Linha 15 em hexadecimal é 0x0F)

    # Invocar a interrupção 10h para posicionar o cursor
    int $0x10                # Chamada de interrupção BIOS para vídeo
    jmp loop_final






_limparTelal:
    # Função de rolagem da tela para cima
    movb $0x06, %ah          # AH = 06h (Função de rolagem para cima)
    movb $0x00, %al          # AL = 00h (Rolagem de toda a tela)
    movb $0x07, %bh          # BH = 07h (Atributo de vídeo normal - branco sobre preto)
    
    # Definir ponto inicial da rolagem (linha 0, coluna 0)
    movb $0x00, %ch          # CH = 00h (Linha inicial)
    movb $0x00, %cl          # CL = 00h (Coluna inicial)

    # Definir ponto final da rolagem (linha 24, coluna 79)
    movb $0x18, %dh          # DH = 24 (Linha final - 0x18 em hexadecimal)
    movb $0x4F, %dl          # DL = 79 (Coluna final - 0x4F em hexadecimal)

    # Invocar a interrupção 10h
    int $0x10                # Chamada de interrupção de vídeo BIOS

    # jmp loop_final
    ret 






_pintarTela:
    # Configurar o modo de vídeo (modo 03h: 80x25 texto, cores CGA)
    movb $0x00, %ah          # AH = 0x00 (Definir modo de vídeo)
    movb $0x03, %al          # AL = 0x03 (Modo de texto 80x25, 16 cores)
    int $0x10                # Chamar interrupção 10h

    # Preencher a tela com espaços (função 09h: escrever caractere e atributo)
    movb $0x09, %ah          # AH = 0x09 (Escrever caractere e atributo)
    movb $0x00, %bh          # BH = 0 (Página de vídeo 0)
    movb $0x20, %al          # AL = 0x20 (ASCII do espaço)
    movw $0x0800, %cx        # CX = 0x0800 (2048 vezes)
    # movb $0x1F, %bl          # BL = 0x1F (Branco intenso sobre fundo azul)
   movb $0x4E, %bl   # Texto amarelo sobre fundo vermelho

    int $0x10                # Chamar interrupção 10h

    # Fim do programa (apenas para demonstração)
    movb $0x00, %ah
    int $0x16                # Aguardar entrada de teclado para terminar





loop_final:
    hlt                     # Halta o sistema (finaliza o programa)
    jmp loop_final          # Loop infinito

# Preenche o setor de boot com 0x55AA
.org 510                   # Garante que o código termine no offset 510
.byte 0x55
.byte 0xaa
