num = int(input())
i = 0
time_list=[]

while i != num:
	input_time = input()
	time_list.append(input_time)
	i = i + 1

start_time = time_list[0][0:5]
finish_time = time_list[0][8:13]

for i in range(1, num):
	if time_list[i][0:5] > start_time:
		start_time = time_list[i][0:5]
		
	if time_list[i][8:13] < finish_time:
		finish_time = time_list[i][8:13]
	
if start_time >= finish_time:
	print("-1")
else:
	print(start_time + " ~ " + finish_time)
