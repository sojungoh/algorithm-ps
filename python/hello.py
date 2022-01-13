class User:
    def __init__(self, name, age, sex):
        self.name = name
        self.age = age
        self.sex = sex
    
    def greet(self):
        print("Nice to meet you " + self.name + "(" + self.age + ")")

u1 = User("Bella", "23", "woman")

u1.greet()    
    