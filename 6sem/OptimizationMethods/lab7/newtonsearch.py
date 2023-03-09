import numpy as np
import sys
from numpy.linalg import norm

np.seterr(all='warn')


# F_HIMMELBLAU is a Himmelblau function
# v = F_HIMMELBLAU(X)
# INPUT ARGUMENTS:
# X - is 2x1 vector of input variables
# OUTPUT ARGUMENTS:
# v is a function value
def fH(X):
    x = X[0]
    y = X[1]
    v = (x ** 2 + y - 11) ** 2 + (x + y ** 2 - 7) ** 2
    return v


# DF_HIMMELBLAU is a Himmelblau function derivative
# v = DF_HIMMELBLAU(X)
# INPUT ARGUMENTS:
# X - is 2x1 vector of input variables
# OUTPUT ARGUMENTS:
# v is a derivative function value

def dfH(X):
    x = X[0]
    y = X[1]
    v = np.copy(X)
    v[0] = 2 * (x ** 2 + y - 11) * (2 * x) + 2 * (x + y ** 2 - 7)
    v[1] = 2 * (x ** 2 + y - 11) + 2 * (x + y ** 2 - 7) * (2 * y)

    return v


# F_ROSENBROCK is a Rosenbrock function
# v = F_ROSENBROCK(X)
# INPUT ARGUMENTS:
# X - is 2x1 vector of input variables
# OUTPUT ARGUMENTS:
# v is a function value

def fR(X):
    x = X[0]
    y = X[1]
    v = (1 - x) ** 2 + 100 * (y - x ** 2) ** 2
    return v


# DF_ROSENBROCK is a Rosenbrock function derivative
# v = DF_ROSENBROCK(X)
# INPUT ARGUMENTS:
# X - is 2x1 vector of input variables
# OUTPUT ARGUMENTS:
# v is a derivative function value

def dfR(X):
    x = X[0]
    y = X[1]
    v = np.copy(X)
    v[0] = -2 * (1 - x) + 200 * (y - x ** 2) * (- 2 * x)
    v[1] = 200 * (y - x ** 2)
    return v


def H(X, tol, df):
    # PLACE YOUR CODE HERE
    epsilon = tol * 0.1
    ei = np.array([[epsilon], [0]])
    ej = np.array([[0], [epsilon]])
    a = 1 / (2 * epsilon)
    h11 = a * (df(X + ei)[0] - df(X - ei)[0])
    h12 = a * (df(X + ei)[1] - df(X - ei)[1])
    h21 = a * (df(X + ej)[0] - df(X - ej)[0])
    h22 = a * (df(X + ej)[1] - df(X - ej)[1])

    ddf = np.array([[h11[0], h12[0]], [h21[0], h22[0]]])
    return ddf


def nsearch(f, df, x0, tol):
    # NSEARCH searches for minimum using Newton method
    # 	answer_ = nsearch(f, df, x0, tol)
    #   INPUT ARGUMENTS
    #   f  - objective function
    #   df - gradient
    # 	x0 - start point
    # 	tol - set for bot range and function value
    #   OUTPUT ARGUMENTS
    #   answer_ = [xmin, fmin, neval, coords]
    # 	xmin is a function minimizer
    # 	fmin = f(xmin)
    # 	neval - number of function evaluations
    #   coords - array of statistics

    # PLACE YOUR CODE HERE

    x = x0
    kmax = 1000
    neval = 0
    coords = []
    k = 1

    while True:
        coords.append(np.copy(x))
        neval += 1
        copy = np.copy(x)
        x = x - np.linalg.lstsq(H(x, tol, df), df(x), -1)[0]
        deltaX = x - copy

        if not ((norm(deltaX) >= tol) and (k < kmax)):
            xmin = x
            break
        else:
            k += 1

    fmin = f(xmin)

    answer_ = [xmin, fmin, neval, coords]
    return answer_
