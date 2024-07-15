q = int(input("Digite o número em decimal: "))
q_original = q
result = ""

while q != 0:
    r = q % 2
    r = str(r)
    result = result + r
    if q == 1 and q == 0:
        r = str(q)
        result = result + r
    q = q / 2


print("A conversão do número em decimal", q_original, "para binário é", result)

"""

214 / 2
014   107
  0

r = 0
result = 0
q = 107

107 / 2
 07   53
  1

r = 1
result = 01
q = 53

53 / 2
13   26
 1

r = 1
result = 011
q = 26

26 / 2
06   13
 0

 r = 0
 result = 0110
 q = 13

13 / 2
 1   6

 r = 1
 result = 01101
 q = 6

6 / 2
0   3

r = 0
result = 011010
q = 3

3 / 2
1   1


"""