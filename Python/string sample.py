a = "hello how are you"
# String Length
print("Length of the string is:", len(a))
print("6th character is:", a[6])
print("Character from 6 to 9 is:", a[6:9] )

# Multiline Strings
str = """sdifuhsdofihs
sfdiughfdghpdfu
sfuoghdfghsufg"""
print(str)

# Looping Through a String
for x in "banana":
  print(x,end=" ")

# Check String
print()
if "how" in a:
    print("Yes how present in a")
if "apple" not in a :
    print("apple not in a")


