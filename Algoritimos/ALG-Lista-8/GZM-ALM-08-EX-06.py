def MDC(a, b):
    if b == 0:
        return a
    else:
        c = a % b
        return MDC(b, c)

#outra forma mais simples de fazer 
def MDC2(a, b):
    return a if b == 0 else MDC(b, a % b)


print(MDC2(18, 60))
