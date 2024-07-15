import Data.Char (toLower, toUpper  ,isUpper)

-- Pdf sobre haskell
-- http://www.decom.ufop.br/romildo/2017-2/bcc222/slides/progfunc.pdf

------------------------------------------------
-- Exercicio01---------------------------------
------------------------------------------------

areaCircuferencia r = pi*(r^2)
let a=2 in areaCircuferencia a 

------------------------------------------------
-- Exercicio02---------------------------------
------------------------------------------------
tipotriangulo a b c
  | a == b && b == c = "Equilatero"
  | a /= b && a /= c && b /= c = "Escaleno"
  | a + b <= c || a + c <= b || b + c <= a = "NAOTRI"
  | otherwise = "isoceles"

{-
 -- Exercicio02  resolvido com if -------------
tipotriangulo a b c =
    if a == b && b == c 
        then "Equilatero" 
    else if a /= b && a /= c && b /= c 
        then "Escaleno"
    else if a + b <= c || a + c <= b || b + c <= a 
        then "NAOTRI"
    else "isoceles"
-}

------------------------------------------------
-- Exercicio03--------------------------------
------------------------------------------------

-- a multiplicação pode ser feita a qualquer tipo numerico que pertence ao num 
-- Eq é necessário porque a função usa a operação de igualdade (==)
-- Sem a restrição Eq, não podemos garantir que o tipo "a" suporta a operação ==
multiplica x y
  | y == 0 || x == 0 = 0
  --necessario para caso onde o numero seja negativo (se não possuir essa linha da erro ao passar um numero negativo )
  | y < 0 = -x + multiplica x (y+1)
  | otherwise = x + multiplica x (y-1)

------------------------------------------------
-- Exercicio04--------------------------------
------------------------------------------------

multiplicaNaturais x y =
    if y == 0 || x == 0
        then 0
    else x + multiplicaNaturais x (y-1)

-- Aplicando a outra forma de recursividade que esta no doc
{-
    multiplicaNaturais1 :: Int -> Int -> Int
    multiplicaNaturais1 x 0 = 0
    multiplicaNaturais1 x y = x + multiplicaNaturais x (y - 1)
-}

------------------------------------------------
-- Exercicio05--------------------------------
------------------------------------------------

menor x y z
    | x <= y && x <= z = x
    | y <= x && y <= z = y
    | otherwise        = z


maior x y z
    | x >= y && x >= z = x
    | y >= x && y >= z = y
    | otherwise        = z

------------------------------------------------
-- Exercicio06--------------------------------
------------------------------------------------

xor x y = x /= y

------------------------------------------------
-- Exercicio07--------------------------------
------------------------------------------------

-- o Y representa a expressão da saida, Aqui, expressão define como cada elemento da 
-- nova lista será gerado a partir dos elementos da lista original
-- o x indica a qual conjunto de entrada a variavel X pertence no caso é xs
clonaNumeros (x:xs) = [y | x <- x:xs, y <- [x, x]]

------------------------------------------------
-- Exercicio08--------------------------------
------------------------------------------------

somaElementos (x:y:xs) = x + y
somaElementos [] = 0

------------------------------------------------
-- Exercicio09--------------------------------
------------------------------------------------

criaLIsta x=
    if x<0
        then [0..(-x)]
    else [0..x]

------------------------------------------------
-- Exercicio 10--------------------------------
------------------------------------------------

parOuImpar (x:xs)=[y | x<-x:xs, y<-[even x]]

{- FUNCIONOU com Map
    tentativaComMap (x:xs) = map (\x -> x `mod` 2 == 0) xs
-}

-- map transforma cada elemento.
-- filter seleciona elementos.


------------------------------------------------
-- Exercicio 11 --------------------------------
------------------------------------------------

-- se o predicado even x for verdadeiro então adiciona na lista Y
soPar (x:xs)= [y | x<-x:xs, even x , y <-[x]]
--soPar2 (x:xs) = filter even x:xs


------------------------------------------------
-- Exercicio 12 --------------------------------
------------------------------------------------

--soMinusculas (x:xs) = map toLower (x:xs)
soMinusculas (x:xs) = [y | x<-x:xs, y <- [toLower x]]


------------------------------------------------
-- Exercicio 13 --------------------------------
------------------------------------------------

-- verificar se é uma vogal (colocar a verificação no lugar da expressão)
-- se for transformar em maiuscula se não so retorna a letra 
substituiVogais :: [Char] -> [Char]
substituiVogais (x:xs)= [ if  toLower x `elem` "aeiou" then toUpper x else x| x<-x:xs ]


------------------------------------------------
-- Exercicio 14 --------------------------------
------------------------------------------------

acrescentarPalavra (x:xs) = [x ++ " Friboi" | x<-x:xs ]


------------------------------------------------
-- Exercicio 15 --------------------------------
------------------------------------------------

-- percorer a lista 
-- se o elemento for iqual a A 

pertence _[]= "Lista vazia"
-- [x | x <- xs, x == a] ele vai retornar ou [] ou com [a]
-- se for [] vai retornar True, que não pertence 
pertence a xs = if  (null [x | x <- xs, x == a]) then "nao pertence"  else "pertence"


------------------------------------------------
-- Exercicio 16 --------------------------------
------------------------------------------------

filtraLista [] = []
filtraLista (x:xs)
  | x `elem` xs = filtraLista xs
  | otherwise = x : filtraLista xs


------------------------------------------------
-- Exercicio 17 --------------------------------
------------------------------------------------

primeirosN n _
  | n <= 0 = []
primeirosN _ [] = []
primeirosN n (x:xs) = x : primeirosN (n - 1) xs

------------------------------------------------j
-- Exercicio 18 --------------------------------
------------------------------------------------

multiplosDe3 = [x | x <- [0..300], x `mod` 3 == 0]







