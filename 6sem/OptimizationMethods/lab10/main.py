from DFPsearch import *
import numpy as np
from DFPdraw import *



def main():
    print("Himmelblau function:")
    x0 = np.array([[1.0], [0.0]])
    tol = 1e-9
    [xmin, f, neval, coords] = dfpsearch(fH, dfH, x0, tol)  #функция Химмельблау
    print(xmin, f, neval)
    draw(coords,  len(coords), fH, "h")

    print("Rosenbrock function:")
    x0 = np.array([[-3], [-3]])
    tol = 1e-9
    [xmin, f, neval, coords] = dfpsearch(fR, dfR, x0, tol)  # функция Розенброка
    print(xmin, f, neval)
    draw(coords,  len(coords), fR, "r")


if __name__ == '__main__':
    main()
