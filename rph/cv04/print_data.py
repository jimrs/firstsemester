import random


def print_data(data):
    for i in range(len(data)):
        for j in range(len(data[i])):
            print(data[i][j], end=' ')
        print()

if __name__ == "__main__":
    seznam = [[1, 2, 3], [2, 3, 4], [3, 4, 5]]
    print_data(seznam)