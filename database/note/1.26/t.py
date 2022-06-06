import foo 
print(foo.x + 1)

li = ["a", "b", "c", "d"]
print(li[-1:])
print(li[-1:])

def make_adder(n):
    
    def adder(m):
        return n + m
    return adder

f = make_adder(3)
print("f(2) =", f(2))

class fraction:
    def __init__(self, num, den): 
        self.num = num
        self.den = den #denominator
		#constructor, self is this in java
		#instance.f() self is instance that the method is called on
    def __getitem__(self, k):
        if k == 0:
            return self.num
        elif k == 1:
            return self.den
        else:
            raise IndexError()        

    def foo(self):
        return 'foo'

    def multiply(self, other):
        new_num = self.num * other.num
        new_den = self.den * other.den
        return fraction(new_num, new_den)

    def __str__(self): #tostring
	    return f'{self.num} / {self.den}'
    
    def __repr__(self):
        return self.__str__()

f1 = fraction(3, 4)
print("f1.num =", f1.num)
print("f1[0] =", f1[0]) #getitem

