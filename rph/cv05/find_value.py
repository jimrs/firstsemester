def value_count(data, value):
    count = 0

    for i in range(0, len(data)):
        for j in range(len(data[i])):
            if data[i][j] == value:
                count += 1
    return count


def value_positions(data, value):
    coordinates = []

    for i in range(0, len(data)):
        for j in range(len(data[i])):
            if data[i][j] == value:
                coordinates.append((i, j))

    return coordinates

if __name__ == "__main__":
    seznam = [[1,2,3],[4,2,3],[7,3,1],[7,8,9],[0,7,5,2,6,7,8,2,4,6,1,2,3,3,8,9,6]]

    print (value_count(seznam, 23))
    print (value_positions(seznam, 1))