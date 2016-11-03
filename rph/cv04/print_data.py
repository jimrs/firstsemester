from line_size import *

def print_data(data):
    for i in range(len(data)):
        for j in range(len(data[i])):
            print(data[i][j], end=' ')
        print()


if __name__ == "__main__":
    seznam = [[0, 1, 1, 1, 1, 0, 0, 0], [1, 1, 0, 1, 0, 1, 1, 1], [0, 1, 1, 0, 0, 1, 0, 1],
              [1, 1, 1, 0, 1, 1, 0, 1], [0, 1, 0, 0, 0, 0, 1, 1], [1, 0, 1, 1, 0, 0, 0, 0],
              [0, 1, 1, 1, 0, 1, 1, 1], [1, 1, 0, 1, 0, 1, 1, 1]]

    r = 7
    c = 7

    print_data(seznam)
    #line = line_size(r, c, seznam)
    #row = column_size(r, c, seznam)
    diagonal = diagonal_size(r, c, seznam)
    #print(line)
    #print(row)
    print(diagonal)
