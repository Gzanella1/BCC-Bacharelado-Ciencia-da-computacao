# Makefile
# Nome do compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -Wall -g

# Nome do executável
TARGET = main

# Arquivos fonte
SRCS = ArvoreBinaria.cpp  Aluno.cpp Main.cpp

# Arquivos objeto
OBJS = ArvoreBinaria.o Aluno.o Main.o

# Regra padrão para construir o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra para construir arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e do executável
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean


# g++ arvorebinaria.cpp main.cpp -o my_program
# ./my_program