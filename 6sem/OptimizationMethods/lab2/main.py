from goldensearch import gsearch
from drawplot import gs2slides

interval = [-2, 10]
tol = 1e-10
[xmin, fmin, neval, coords] = gsearch(interval, tol)
print([xmin, fmin, neval])

gs2slides(interval, coords)
