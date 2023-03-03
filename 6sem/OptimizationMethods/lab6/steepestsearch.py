import numpy as np
import sys
from numpy.linalg import norm


def goldensectionsearch(f, interval, tol):
    # PLACE YOUR CODE HERE

    fi = (1 + np.sqrt(5)) / 2
    k = 1
    a = interval[0]
    b = interval[1]
    L = b - a
    lamba = b - L / fi
    mu = a + L / fi
    neval = 0
    while True:
        neval += 1
        if f(lamba) > f(mu):
            a = lamba
            xmin = mu
            lamba = mu
            L = b - a
            mu = a + L / fi
        else:
            b = mu
            xmin = lamba
            mu = lamba
            L = b - a
            lamba = b - L / fi
        if np.abs(L) <= tol:
            break
        else:
            k += 1

    fmin = f(xmin)

    answer_ = xmin
    return answer_


# F_HIMMELBLAU is a Himmelblau function
# 	v = F_HIMMELBLAU(X)
#	INPUT ARGUMENTS:
#	X - is 2x1 vector of input variables
#	OUTPUT ARGUMENTS:
#	v is a function value
def fH(X):
    x = X[0]
    y = X[1]
    v = (x ** 2 + y - 11) ** 2 + (x + y ** 2 - 7) ** 2
    return v


# DF_HIMMELBLAU is a Himmelblau function derivative
# 	v = DF_HIMMELBLAU(X)
#	INPUT ARGUMENTS:
#	X - is 2x1 vector of input variables
#	OUTPUT ARGUMENTS:
#	v is a derivative function value

def dfH(X):
    x = X[0]
    y = X[1]
    v = np.copy(X)
    v[0] = 2 * (x ** 2 + y - 11) * (2 * x) + 2 * (x + y ** 2 - 7)
    v[1] = 2 * (x ** 2 + y - 11) + 2 * (x + y ** 2 - 7) * (2 * y)

    return v


# F_ROSENBROCK is a Rosenbrock function
# 	v = F_ROSENBROCK(X)
#	INPUT ARGUMENTS:
#	X - is 2x1 vector of input variables
#	OUTPUT ARGUMENTS:
#	v is a function value

def fR(X):
    x = X[0]
    y = X[1]
    v = (1 - x) ** 2 + 100 * (y - x ** 2) ** 2
    return v


# DF_ROSENBROCK is a Rosenbrock function derivative
# 	v = DF_ROSENBROCK(X)
#	INPUT ARGUMENTS:
#	X - is 2x1 vector of input variables
#	OUTPUT ARGUMENTS:
#	v is a derivative function value

def dfR(X):
    x = X[0]
    y = X[1]
    v = np.copy(X)
    v[0] = -2 * (1 - x) + 200 * (y - x ** 2) * (- 2 * x)
    v[1] = 200 * (y - x ** 2)
    return v


def sdsearch(f, df, x0, tol):
    # SDSEARCH searches for minimum using steepest descent method
    # 	answer_ = sdsearch(f, df, x0, tol)
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
    neval = 0
    coords = []
    kmax = 1000
    interval = [0, 1]
    x = x0
    k = 1

    while True:
        coords.append(np.copy(x))
        neval += 1
        fidim_po_midu = lambda alpha: f(x - alpha * df(x))
        alpha = goldensectionsearch(fidim_po_midu, interval, tol)

        copy = np.copy(x)
        x = x - alpha * df(x)
        deltaX = x - copy
        if not ((norm(deltaX) >= tol) and (k < kmax)):
            xmin = x
            break
        else:
            k += 1

    fmin = f(xmin)

    answer_ = [xmin, fmin, neval, coords]
    return answer_
