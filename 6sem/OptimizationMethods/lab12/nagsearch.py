import numpy as np
import sys
from numpy.linalg import norm
from numpy.linalg import inv

np.seterr(divide='ignore', invalid='ignore')


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


def nagsearch(f, df, x0, tol):
    # NAGSEARCH searches for minimum using the Nesterov accelerated gradient method
    # 	answer_ = nagsearch(f, df, x0, tol)
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
    kmax = 1000
    coordinates = []
    neval = 1
    al = 0.05
    nu = al / 10
    gamma = 0.75
    x = np.copy(x0)
    y = np.copy(x)
    while True:
        coordinates.append(x)
        x_old = np.copy(x)
        x = y - nu * df(y)
        y = x_old + gamma * (x - x_old)

        if not (norm(df(y)) >= tol) and (neval < kmax):
            xmin = x
            break
        neval += 1

    answer_ = [xmin, f(xmin), neval, coordinates]
    return answer_
