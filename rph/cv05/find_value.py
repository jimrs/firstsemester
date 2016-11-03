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

