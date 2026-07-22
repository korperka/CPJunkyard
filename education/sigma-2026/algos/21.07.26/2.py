from random import randint

n = int(input())
a = [randint(1, n) for _ in range(n+1)]
ans = "не найден"

for i in range(len(a)-1):
    if a[i] == a[i+1]:
        ans = i

print(a)
print("Повторяющийся элемент: ", a[ans])