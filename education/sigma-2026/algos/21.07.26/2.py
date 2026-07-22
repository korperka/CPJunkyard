from random import randint, shuffle

n = int(input())
a = list(range(1, n+1)) + [randint(1, n)]
shuffle(a)

print(a)

i = j = a[0]
while True:
    i = a[i]
    j = a[a[j]]

    if i == j:
        break

i = a[0]
while True:
    i = a[i]
    j = a[j]

    if i == j:
        break

print(i)