time_line=[(1,4),(3,5),(0,6),(5,7),(3,8),(5,9),(6,10),(8,11),(8,12),(12,14)]
result_line=[]
num=11

'''
time_line=[]
num2=input()
num=int(num2)
for i in range(num):
    print(i)
    #t1,t2=map(int,input('3과목의 값입력).split()
    t1,t2=input().split(" ")
    t=(int(t1),int(t2))
    time_line.append(t)
'''
time_line.sort(key=lambda t:t[0], reverse=False)

print(time_line) 


while len(time_line)>0:
    temp=time_line[0]
    for (t1,t2) in time_line:
        if temp[1]>t2 :
            temp=(t1,t2)
    result_line.append(temp)
    for (t1,t2) in time_line:
        if temp[0]>=t1 or temp[1]>=t2 or temp[1]>t1:
            print((t1,t2),"deleted")
            time_line=time_line[:time_line.index((t1,t2))]+time_line[time_line.index((t1,t2))+1:]
            if len(time_line)==0:
            	break
    
print(result_line)
print(len(result_line))