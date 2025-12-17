# START PATTERN
n = int(input("Enter the limit"))
for i in range(n):
    for j in range(i+1):
        print("*",end=" ")
    print()
"""
OUTPUT
Enter the limit5
* 
* * 
* * * 
* * * * 
* * * * * 
"""

# NUMBER PATTERN
for i in range(n):
    for j in range(i+1):
        print(j+1,end=" ")
    print()
"""
OUTPUT
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 

"""
