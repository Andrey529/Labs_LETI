import numpy as np


def f(x): return x ** 2 - 10 * np.cos(0.3 * np.pi * x) - 20


def df(x): return 2 * x + 3 * np.pi * np.sin(0.3 * np.pi * x)


def ssearch(interval, tol):
    # SSEARCH searches for minimum using secant method
    # 	answer_ = ssearch(interval,tol)
    #   INPUT ARGUMENTS
    # 	interval = [a, b] - search interval
    # 	tol - set for bot range and function value
    #   OUTPUT ARGUMENTS
    #   answer_ = [xmin, fmin, neval, coords]
    # 	xmin is a function minimizer
    # 	fmin = f(xmin)
    # 	neval - number of function evaluations
    #   coords - array of x values found during optimization

    # PLACE YOUR CODE HERE
    a = interval[0]
    b = interval[1]
    k = 1
    neval = 0
    coords = []
    while True:
        x = b - df(b) * (b - a) / (df(b) - df(a))
        neval += 1
        coords.append([x, a, b])
        if df(x) > 0:
            b = x
        else:
            a = x
        if (np.abs(df(x))) <= tol or (np.abs(b - a)) <= tol:
            xmin = x
            break
        else:
            k += 1

    fmin = f(xmin)

    answer_ = [xmin, fmin, neval, coords]
    return answer_
