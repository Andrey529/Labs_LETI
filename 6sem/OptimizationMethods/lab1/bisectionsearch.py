import numpy as np


def f(x): return 2 * (x ** 2) - 9 * x - 31


def df(x): return 4 * x - 9


def bsearch(interval, tol):
    # searches for minimum using bisection method
    # arguments: bisectionsearch(f,df,interval,tol)
    # f - an objective function
    # df -  an objective function derivative
    # interval = [a, b] - search interval
    # tol - tolerance for both range and function value
    # output: [xmin, fmin, neval, coords]
    # xmin - value of x in fmin
    # fmin - minimul value of f
    # neval - number of function evaluations
    # coords - array of x values found during optimization

    # PLACE YOUR CODE HERE
    k = 1
    a = interval[0]
    b = interval[1]
    coords = []
    neval = 0
    while np.abs(b - a) > tol and np.abs(df(a)) > tol:
        print(b - a)
        x = (a + b) / 2
        coords.append(x)
        neval += 1
        if df(x) > 0:
            b = x
        else:
            a = x
        k += 1

    xmin = x
    fmin = f(x)

    answer_ = [xmin, fmin, neval, coords]
    return answer_
