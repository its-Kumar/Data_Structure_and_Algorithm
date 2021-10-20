print("This program sorts the given array using bubble sort technique")
n=int(input("Enter the number of elements you want to insert in the array "))
DATA=[]
for i in range(0,n):
    m=int(input("Enter element "))
    DATA.append(m)

print("The inserted array is", DATA)

for j in range(0,n):
    for k in range(0,n-j-1):
        if DATA[k]>DATA[k+1]:
            t=DATA[k]
            DATA[k]=DATA[k+1]
            DATA[k+1]=t

print("Sorted array", DATA)
