-- EXERCICIO 01 --------------------------
-- Melhorar o exercicio 
Resultado da expressão: (false, -4)

sera falso pois 1 não é igual a 4, 


-- EXERCICIO 02 --------------------------

-- f :: (Integral b, Num a) => a -> b -> a
f x y = x^y
-- g :: Floating a => a -> a -> a
g x y = x**y

{- Teste: os resultados 

Não apresentam o mesmo comportamento pois as mesmas entradas para as funções
f, g resultou no tipo da saida diferentes.

f 3 5
243

g 3 5
243.0

-}

-- EXERCICIO 03 --------------------------
dobro :: Double -> Double
dobro x = x*2

-- EXERCICIO 04 --------------------------

incremento x = x + 1
decremento x = x - 1


-- EXERCICIO 05 --------------------------

-- MELHORAR A RESPOSTA NÃO GANHAREI O CERTO 

{-
:t decremento (incremento 9)
decremento (incremento 9) :: Num a => a 


O comando recebe qualquer tipo da classe Num e retorna esse mesmo tipo.
Ex: Se eu inserir um valor int o valor da saida sera int

-}


-- EXERCICIO 06 ------------------------

sobeDesce :: (Num t, Num t) => (t, t) -> (t, t)
sobeDesce (x,y) = (x+1,y-1)

-- EXERCICIO 07 ------------------------

sobeDesce2 (x,y) = (incremento(x), decremento(y))

-- EXERCICIO 08 ------------------------

trocaValor (a, b) = (b,a)
    
-- EXERCICIO 09 ------------------------

{-
negate 5
-5
-}


