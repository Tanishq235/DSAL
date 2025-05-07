class setadt:
    def __init__(self):
        self.elements=[]
        
    def add(self,element):
        if element not in self.elements:
            self.elements.append(element)
            
    def remove(self,element):
        if element in self.elements:
            self.elements.remove(element)
            
    def display(self):
        for element in self.elements:
            print(element)
    
    def search(self,element):
        return element in self.elements       
    
    def iterator(self):
        return iter(self.elements)
    
    def size(self):
        return len(self.elements)
    
    def intersection(self, other_set):
        result=setadt()
        if other_set:
            for element in self.elements:
                if element in other_set.elements:
                    result.add(element)
        return result
                    
    def union(self, other_set):
        result =setadt()
        if other_set:
            for element in self.elements:
                result.add(element)
            for element in other_set.elements:
                result.add(element)
        else:
            for element in self.elements:
                result.add(element)
        return result
    
    def difference(self,other_set):
        result=setadt()
        if other_set:
            for element in self.elements:
                if element not in other_set.elements:
                    result.add(element)
        else:
            for element in self.elements:
                result.add(element)
        return result
    
    def subset(self,other_set):
        if other_set:
            for element in self.elements:
                if element not in other_set.elements:
                    return False
        return True

set1 = setadt()
set2 = setadt()
                      
set1.add(1)    
set1.add(2)
set1.add(3)
    
set2.add(5)    
set2.add(4)
set2.add(8)
    
print("Set 1")
set1.display()
print("Set 2")
set2.display()
    
print("set 1 size", set1.size())
print("set 2 size", set2.size())

print("set 1 contains 2",set1.search(2))

difference= set1.difference(set2)
print("Difference(set1-set2): ",list(difference.iterator()))

union=set1.union(set2)
print("union",list(union.iterator()))

print("is set1 a subset of set2",set1.subset(set2))

intersection = set1.intersection(set2)
print("interaction: ", list(intersection.iterator()))        
    
    
    
    
            
