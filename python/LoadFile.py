
import time 

LoadedData=[[]for _ in range(200)]

#------------------------------------------------------------------------------
def LoadFile(n):
    f_name = "input/"+str(n)+".txt"
    with open(f_name, 'r', encoding='utf-8') as f:
        content = f.read()
    
    content = content.split("\n")

    LoadedData[n-1].append(content[0])
    LoadedData[n-1].append(content[1])

#==============================================================================
def main():

    for n in range(1,200):
        LoadFile(n)

if __name__=="__main__":

    start = time.time()
    main()
    print(LoadedData)
    end   = time.time()

    print(end-start)
