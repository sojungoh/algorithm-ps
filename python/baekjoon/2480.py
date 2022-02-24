number = list(map(int, input().split()))

number.sort()
pay = 0

if number[0] == number[1] and number[1] == number[2]:
    pay = 10000 + number[0]*1000
    
elif number[0] != number[1] and number[1] != number[2] and number[2] != number[0]:
    pay = number[2]*100
    
else:
    if number[0] == number[1]:
        pay = 1000 + number[0]*100
        
    if number[1] == number[2]:
        pay = 1000 + number[1]*100
        
print(pay)