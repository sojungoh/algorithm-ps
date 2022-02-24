hour, minute = map(int, input().split())
cookingTime = int(input())

cookedMinute = minute + cookingTime

if cookedMinute < 60:
    cookedHour = hour
    print(cookedHour, cookedMinute)
else:
    cookedHour = hour + cookedMinute // 60
    cookedMinute %= 60
    
    if cookedHour >= 24:
        cookedHour %= 24
        
    print(cookedHour, cookedMinute)
