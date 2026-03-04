import math
print("Master Theorem Solver")
print("Form: T(n) = aT(n/b) + n^k")

a = int(input("Enter value of a: "))
b = int(input("Enter value of b: "))
k = int(input("Enter power k for f(n) = n^k: "))

log_b_a = math.log(a, b)

with open("master_theorem_output.txt", "w", encoding="utf-8") as file:
    file.write("MASTER THEOREM SOLUTION\n")
    file.write("----------------------\n")
    file.write(f"Given Recurrence: T(n) = {a}T(n/{b}) + n^{k}\n")
    file.write(f"log_b(a) = {log_b_a:.2f}\n\n")

    if k < log_b_a:
        file.write("Case 1: f(n) = O(n^k), where k < log_b(a)\n")
        file.write(f"Final Time Complexity: Theta(n^{log_b_a:.2f})\n")
    elif abs(k - log_b_a) < 1e-6:
        file.write("Case 2: f(n) = Theta(n^log_b(a))\n")
        file.write("Final Time Complexity: Theta(n^k log n)\n")
    else:
        file.write("Case 3: f(n) = Omega(n^k), where k > log_b(a)\n")
        file.write(f"Final Time Complexity: Theta(n^{k})\n")
print("Output saved to master_theorem_output.txt")
"""
OUTPUT
Master Theorem Solver
Form: T(n) = aT(n/b) + n^k
Enter value of a: 4
Enter value of b: 2
Enter power k for f(n) = n^k: 2
Output saved to master_theorem_output.txt

master_theorem_output.txt:
MASTER THEOREM SOLUTION
----------------------
Given Recurrence: T(n) = 4T(n/2) + n^2
log_b(a) = 2.00

Case 2: f(n) = Theta(n^log_b(a))
Final Time Complexity: Theta(n^k log n)
"""