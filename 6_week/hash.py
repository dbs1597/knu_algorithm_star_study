num1 = int(input())

a = input().split(' ')

a = set(a)

num2 = int(input())

b = input().split(' ')

for i in range(num2):
    if b[i] in a:
        print(1)
    else:
        print(0)