from random import randint

def guess(num):
    attempt = input("ВВЕДИТЕ число: ")

    if len(attempt) != 4:
        print("Число должно быть четырёхзначным")
        guess(num)
        return

    if attempt == num:
        print(f"Вы угадали число - {num}!")
        return

    biki = sum([1 for i in range(len(num)-1) if attempt[i] == num[i]])
    korovi = sum([1 for i in num if i in attempt]) - biki

    print(f"Быков: {biki}, коров: {korovi}")
    guess(num)


num = str(randint(1000, 9999))
guess(num)
