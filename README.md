Name Deng chol kon
Roll Number 202511436


# Student Result Management System

def calculate_result(m1, m2, m3):
    total = m1 + m2 + m3
    average = total / 3

    if average >= 50:
        result = "Passed"
    else:
        result = "Failed"

    return total, average, result


while True:
    name = input("Enter student name: ")

    mark1 = int(input("Enter marks for Subject 1: "))
    mark2 = int(input("Enter marks for Subject 2: "))
    mark3 = int(input("Enter marks for Subject 3: "))

    total, average, result = calculate_result(mark1, mark2, mark3)

    print("\n--- Student Result ---")
    print("Name:", name)
    print("Total Marks:", total)
    print("Average Marks:", average)
    print("Result:", result)

    choice = input("\nDo you want to enter another student? (yes/no): ")

    if choice.lower() != "yes":
        print("Program Ended")
        break
