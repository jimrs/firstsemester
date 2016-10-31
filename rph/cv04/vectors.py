class MyVector:
    def __init__(self, vector):  # constructor taking 1 parameter
        self.vector = vector

    def get_vector(self):  # function that returns vector field
        return self.vector

    def __mul__(self, other):  # overloading multiplication to scalar product
        scalar = 0
        for i in range(0, min(len(self.vector), len(other.vector))):
            scalar += self.vector[i] * other.vector[i]
        return scalar

    def __add__(self, other):
        a = MyVector(self.get_vector())
        for i in range(0, len(a.vector)):
            a.vector[i] += other.vector[i]
        return a


if __name__ == "__main__":
    a = MyVector([1, 2, 3])
    b = MyVector([2, 3, 4])
    c = a+b
    print(c.get_vector())