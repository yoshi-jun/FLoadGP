# LoadFileNumpy.py
import numpy as np
import time 

LoadedData=[[]for _ in range(200)]

#------------------------------------------------------------------------------
def LoadFileNumpy(n):
    f_name = "input/"+str(n)+".txt"

    np.loadtxt(f_name)