class Stack:
    def __init__(self):
        self.data:list=list()
        self.currentPointer:int=0

    def push(self,element):
        if self.currentPointer>=len(self.data) :
            self.data.append(element)
        else :
            self.data[self.currentPointer]=element

        self.currentPointer+=1

    def pop(self,):
        if self.currentPointer==0:
            raise Exception("Stack underflow")
        
        self.currentPointer-=1
        return self.data[self.currentPointer]
    
    def isEmpty(self):
        return self.currentPointer==0
    
    def isFull(self):
        return self.currentPointer==len(self.data)
    

