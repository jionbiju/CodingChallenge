# Write a Python program to generate prime numbers within a certain range.
start = int(input("Enter starting number"))
end = int(input("Enter ending number"))
print("Prime numbers between {} and {} are:".format(start,end))
for i in range(start,end+1):
    if i>1:
        flag = 0
        for j in range(2,i):
            if i%j==0:
                flag=1
                break
        if flag==0:
            print(i)
"""
OUTPUT
Enter starting number-7
Enter ending number20
Prime numbers between -7 and 20 are:
2
3
5
7
11
13
17
19
"""