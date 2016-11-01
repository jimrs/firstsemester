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

    r = 4
    c = 1

    line = line_size(r, c, seznam)
    row = column_size(r, c, seznam)
    # diagonal = diagonal_size(r, c, seznam)
    print_data(seznam)
    print(line)
    print(row)
    # print(diagonal)
