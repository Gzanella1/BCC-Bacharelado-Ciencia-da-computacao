class Carro:
    def __init__(self, marca):
        self.marca = marca

carro = Carro("Ford")
print(carro.marca)  # Saída: Ford

setattr(carro, "marca", "Chevrolet")
print(carro.marca)  # Saída: Chevrolet
