from nagsearch import *
import numpy as np
from nagDraw import *


def main():
    print("Himmelblau function:")
    x0 = np.array([[0.0], [1.0]])
    tol = 1e-3
    [xmin, f, neval, coords] = nagsearch(fH, dfH, x0, tol)  # функция Химмельблау
    print(xmin, f, neval)
    draw(coords,  len(coords), fH)


if __name__ == '__main__':
    main()