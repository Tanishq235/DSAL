class SetADT:
    def __init__(self):
        self.elements = []

    def add(self, element):
        if element not in self.elements:
            self.elements.append(element)

    def display(self):
        print(self.elements)

    def search(self, element):
        return element in self.elements

    def size(self):
        return len(self.elements)

    def union(self, other):
        result = SetADT()
        for e in self.elements:
            result.add(e)
        for e in other.elements:
            result.add(e)
        return result

    def intersection(self, other):
        result = SetADT()
        for e in self.elements:
            if e in other.elements:
                result.add(e)
        return result

    def difference(self, other):
        result = SetADT()
        for e in self.elements:
            if e not in other.elements:
                result.add(e)
        return result

    def is_subset(self, other):
        for e in self.elements:
            if e not in other.elements:
                return False
        return True

# Create two sets
set1 = SetADT()
set2 = SetADT()

# Input sets
print("Enter elements for Set 1 (comma separated):")
for e in input().split(","):
    set1.add(e.strip())

print("Enter elements for Set 2 (comma separated):")
for e in input().split(","):
    set2.add(e.strip())

# Simple menu
while True:
    print("\n1. Display Sets\n2. Union\n3. Intersection\n4. Difference (Set1 - Set2)")
    print("5. Is Set1 Subset of Set2?\n6. Search in Set1\n7. Sizes\n8. Exit")
    choice = input("Enter choice: ")

    if choice == '1':
        print("Set 1:", end=" "); set1.display()
        print("Set 2:", end=" "); set2.display()
    elif choice == '2':
        print("Union:", end=" "); set1.union(set2).display()
    elif choice == '3':
        print("Intersection:", end=" "); set1.intersection(set2).display()
    elif choice == '4':
        print("Difference:", end=" "); set1.difference(set2).display()
    elif choice == '5':
        print("Yes" if set1.is_subset(set2) else "No")
    elif choice == '6':
        item = input("Enter item to search in Set 1: ")
        print("Found" if set1.search(item) else "Not Found")
    elif choice == '7':
        print("Size of Set 1:", set1.size())
        print("Size of Set 2:", set2.size())
    elif choice == '8':
        print("Goodbye!")
        break
    else:
        print("Invalid choice.")
