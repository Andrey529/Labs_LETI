import numpy as np


def f(x): return (x - 3) ** 2 - 3 * x + x ** 2 - 40


def gsearch(interval, tol):
    # GOLDENSECTIONSEARCH searches for minimum using golden section
    # 	[xmin, fmin, neval] = GOLDENSECTIONSEARCH(f,interval,tol)
    #   INPUT ARGUMENTS
    # 	f is a function
    # 	interval = [a, b] - search interval
    # 	tol - set for bot range and function value
    #   OUTPUT ARGUMENTS
    # 	xmin is a function minimizer
    # 	fmin = f(xmin)
    # 	neval - number of function evaluations
    #   coords - array of statistics,  coord[i][:] =  [x1,x2, a, b]

    # PLACE YOUR CODE HERE
    fi = (1 + np.sqrt(5)) / 2
    k = 1
    a = interval[0]
    b = interval[1]
    L = b - a
    lamba = b - L / fi
    mu = a + L / fi
    coord = []
    neval = 0
    while True:
        neval += 1
        coord.append([lamba, mu, a, b])
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

    answer_ = [xmin, fmin, neval, coord]
    return answer_