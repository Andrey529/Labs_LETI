import numpy as np


def f(x): return x ** 2 - 10 * np.cos(0.3 * np.pi * x) - 20


def df(x): return 2 * x + 3 * np.pi * np.sin(0.3 * np.pi * x)


def ddf(x): return 2 + 0.9 * (np.pi ** 2) * np.cos(0.3 * np.pi * x)


def nsearch(tol, x0):
    # NSEARCH searches for minimum using Newton method
    # 	answer_ = nsearch(tol,x0)
    #   INPUT ARGUMENTS
    # 	tol - set for bot range and function value
    #	x0 - starting point
    #   OUTPUT ARGUMENTS
    #   answer_ = [xmin, fmin, neval, coords]
    # 	xmin is a function minimizer
    # 	fmin = f(xmin)
    # 	neval - number of function evaluations
    #   coords - array of x values found during optimization

    # PLACE YOUR CODE HERE
    x = x0 - f(x0) / df(x0)
    k = 1
    neval = 0
    coords = []
    while True:
        coords.append(x)
        neval += 3
        xOld = x
        x = x - df(x) / ddf(x)
        if np.abs(x - xOld) <= tol:
            xmin = x
            break
        else:
            k += 1

    fmin = f(xmin)

    answer_ = [xmin, fmin, neval, coords]
    return answer_
