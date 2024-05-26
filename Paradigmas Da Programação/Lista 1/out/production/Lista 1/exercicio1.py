def recursividade(n: int ):
    if n == 0:
        print("boom!")     
    else:
        print(n)
        recursividade(n-1) 
          

recursividade(5)
        