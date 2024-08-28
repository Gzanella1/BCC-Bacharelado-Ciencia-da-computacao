// Classe Item (representa cada nodo da pilha)

class Item
{
public:
  int valor; //Valor
  Item* proximo; // Próximo

  Item(int v, Item* p = nullptr) : valor(v), proximo(p) {}

};