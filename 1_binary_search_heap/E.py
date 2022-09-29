a, k, b, m, x = map(int, input().split())
left = 0
right = x
while right - left > 1:
    middle = (left + right) // 2
    if (a * middle - (middle // k) * a) + (b * middle - (middle // m) * b) >= x:
        right = middle
    else:
        left = middle
print(right)
