a, b, c, d = map(int, input().split())
left = -100000000
right = 100000000
eps = 10 ** -6
while right - left > eps:
    middle = (left + right) / 2
    if a > 0:
        if (a * middle ** 3 + b * middle ** 2 + c * middle + d) > 0:
            right = middle
        else:
            left = middle
    else:
        if (a * middle ** 3 + b * middle ** 2 + c * middle + d) > 0:
            left = middle
        else:
            right = middle
print(right)
