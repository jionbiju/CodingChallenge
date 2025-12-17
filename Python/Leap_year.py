year = int(input("Enter a year:"))
if year%4 == 0:
    if year%100 == 0:
        if year % 400 == 0:
            print(year," is leap year.")
        else:
            print(year, " is not leap year.")
    else:
        print(year, " is leap year.")
else:
    print(year, " is not leap year.")

"""
OUTPUT
Enter a year:1900
1900  is not leap year.

Enter a year:2024
2024  is leap year.
"""