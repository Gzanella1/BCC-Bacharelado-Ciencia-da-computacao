class Calculadora:
    def soma(self, a, b):
        return a + b

    def subtracao(self, a, b):
        return a - b

calculadora = Calculadora()

# Acessando e chamando métodos dinamicamente
operacao = "soma"
resultado = getattr(calculadora, operacao)(5, 3)
print(f"Resultado da {operacao}: {resultado}")
