class math:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        
    def add(self):
        print(self.x + self.y)
        
    def sub(self):
        print(self.x - self.y)
    
    def mul(self):
        print(self.x * self.y)
        
    def div(self):
        print(self.x // self.y)
        
    def rem(self):
        print(self.x % self.y)    

x, y = map(int, input().split())

test = math(x, y)

test.add(); test.sub(); test.mul(); test.div(); test.rem()
