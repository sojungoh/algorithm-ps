#내 풀이
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


#다른 풀이
a, b, c = sorted(map(int, input().split()))
print([c, b+10, b*10+100][[a, b, c].count(b)-1]*100)

"""[a,b,c] 리스트에서 b 개수 세기
b가 3개면 (b*10+100)*100 = b*1000 + 10000
b가 2개면 (b+10)*100 = b*100 + 1000
b가 1개면 가장 큰 c 선택 c*100"""