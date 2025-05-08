# To create ADT that implement the "set" concept.
# a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the
# value
# c. Contains (element) Return true if element is in collection, d. Size () Return number of
# values in collection Iterator () Return an iterator used to loop over collection, e.
# Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset

class setADT:
    def __init__(self):
        self.elements = []
        
    def add(self,element):
        if element not in self.elements:
            self.elements.append(element)
            
    def remove(self,element):
        if element in self.elements:
            self.elements.remove(element)
            
    def  iterator(self):
        return iter(self.elements)
        
    def search(self,element):
        if element in self.elements:
            return element
        
    def size(self):
        return len(self.elements)
        
    def Display(self):
        print("Set elements : ", self.elements)
        
    def intersection(self,other_set):
        result = setADT()
        for element in self.elements:
            if element in other_set.elements:
                result.add(element)
        return result
        
    def Union(self,other_set):
        result = setADT()
        for element in self.elements:
            result.add(element)
        for element in other_set.elements:
            result.add(element)
        return result
        
    def difference(self,other_set):
        result = setADT()
        for element in self.elements:
            if element not in other_set.elements:
                result.add(element)
        return result
        
    def is_subset(self,other_set):
        for element in self.elements:
            if element in other_set.elements:
                return True
        return False
        
def menu():
    set1 = setADT()
    set2 = setADT()
    
    while True:
        print("---MENU---")
        print("1.Add element in set1")
        print("2.Add element in set2")
        print("3.Remove element from set1")
        print("4.Remove element from set2")
        print("5.Size of set1")
        print("6.Size of set2")
        print("7.Display")
        print("8.Intersection")
        print("9.Union")
        print("10.Difference")
        print("11.is_subset(s1-s2)")
        print("12.Search element in set 1")
        print("13.Search element in set 2")
        print("14.Exit")
        choice = input("Enter the choice (1-12) : ")
        
        if choice == '1':
            ele = int(input("Enter the element to insertin set 1 : "))
            set1.add(ele)
            
        elif choice == '2':
            ele = int(input("Enter the element to insertin set 2 : "))
            set2.add(ele)
            
        elif choice == '3':
            ele = int(input("Enter the element to remove from set 1 : "))
            set1.remove(ele)
            
        elif choice == '4':
            ele = int(input("Enter the element to remove from set 2 : "))
            set2.remove(ele)  
            
        elif choice == '5':
              print("Size of Set 1:", set1.size())
            
        elif choice == '6':
            print("Size of Set 2:", set2.size())
            
        elif choice == '7':
            print("set 1 :")
            set1.Display()
            print("set 2 :")
            set2.Display()
            
        elif choice == '8':
            result = set1.intersection(set2)
            print("The Intersection is : ", list(result.iterator()))
            
        elif choice == '9':
            result = set1.Union(set2)
            print("The Unionn is : ", list(result.iterator()))
            
        elif choice == '10':    
            result = set1.difference(set2)
            print("The Difference is : ", list(result.iterator()))
            
        elif choice == '11':
            result = set1.is_subset(set2)
            print(result)
            print("Yes" if set1.is_subset(set2) else "No")
            
        elif choice == '12':
            ele = int(input("Enter the element to be search : "))
            print("found element in set1 "if set1.search(ele) else "not found in set 1")
            
        elif choice == '13':
            ele = int(input("Enter the element to be search : "))
            print("found element in set2 "if set2.search(ele) else "not found in set 2")    
            
        elif choice == '14':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")
            
menu()            

            
        
        
        
        
        
    
    
    
                
            
