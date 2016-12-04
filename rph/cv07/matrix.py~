class MyMatrix:
    def __init__(self, matrix=[]):
        self.matrix = matrix
    
    def get_matrix(self):
        return self.matrix

    def save(self, filename):
        with open(filename, 'w', encoding='utf-8') as f:
            for element in self.matrix:
                line = str(element).replace('[', '')
                line = line.replace(']', '')
                # or
                # line = str(element).strip('[]')
                line = line.replace(',', '')

                f.write(line + '\n')

    def load(self, filename):
        with open(filename, 'r', encoding='utf-8') as f:
            for line in f:
                line = line.strip()
                line = line.split()

                numbers = []
                for element in line:
                    element = int(element)
                    numbers.append(element)

                #line = [int(element) for element in line]

                self.matrix.append(numbers)


if __name__ == "__main__":
    a = MyMatrix([[1, 2, 3], [2, 3, 4]])
    a.save("matrix.txt")
    value_a = a.get_matrix()
    b = MyMatrix()
    b.load("matrix.txt")
    value_b = b.get_matrix()
    print("Value of matrix A:")
    print(value_a)
    print("Value of matrix B:")
    print(value_b)
    print("Is it true that matrix A = matrix B?")
    print(value_a == value_b)
