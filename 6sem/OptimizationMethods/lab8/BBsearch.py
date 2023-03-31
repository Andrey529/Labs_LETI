import numpy as np
import sys
from numpy.linalg import norm


def goldensectionsearch(f, interval, tol):

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

    answer_ = xmin
    return answer_


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


def bbsearch(f, df, x0, tol):
    # BBSEARCH searches for minimum using stabilized BB1 method
    # 	answer_ = bbsearch(f, df, x0, tol)
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
    x = x0
    neval = 0
    coords = []
    k = 1
    D = 0.1
    g = lambda ak : f(x0 - ak * df(x0))
    ak = goldensectionsearch(g, [0,1], tol)

    while True:
        neval += 1

        x_prev = np.copy(x)
        x = x_prev - ak * df(x_prev)
        coords.append(np.copy(x))

        delta_x = abs(x - x_prev)
        delta_g = abs(df(x) - df(x_prev))

        ak = np.dot(np.transpose(delta_x), delta_x) / np.dot(np.transpose(delta_x), delta_g)
        ak_stab = D / norm(df(x))

        ak = min(ak, ak_stab)

        if not ((norm(delta_x) >= tol) and (k < kmax)):
            break
        else:
            k += 1

    xmin = x
    fmin = f(xmin)



    answer_ = [xmin, fmin, neval, coords]
    return answer_
