def line_size(r, c, data):
    starting_point = data[r][c]
    size = 0

    for i in range(c, len(data[r]), +1):
        if starting_point != data[r][i]:
            break
        if starting_point == data[r][i]:
            size += 1

    for i in range(c-1, 0, -1):
        if starting_point != data[r][i]:
            break
        if starting_point == data[r][i]:
            size += 1

    return size


def column_size(r, c, data):
    starting_point = data[r][c]
    size = 0

    for i in range(r, len(data), +1):
        if starting_point != data[i][c]:
            break
        if starting_point == data[i][c]:
            size += 1

    for i in range(r-1, 0, -1):
        if starting_point != data[i][c]:
            break
        if starting_point == data[i][c]:
            size += 1

    return size


def diagonal_size(r, c, data):
    starting_point = data[r][c]
    size = 0

    for i in range(0, max((len(data) - r), (len(data) - c)), +1):
        if (r-i < 0) or (c-i < 0):
            break
        if starting_point != data[r+i][c+i]:
            break
        print("coor " + str(r + i) + ":" + str(c + i) + " | value " + str(data[r + i][c + i]))
        if starting_point == data[r+i][c+i]:
            size += 1

    for i in range(1, max((len(data) - r), (len(data) - c)), +1):
        if (r-i < 0) or (c-i < 0):
            break
        if starting_point != data[r-i][c-i]:
            break
        print("coor " + str(r - i) + ":" + str(c - i) + " | value " + str(data[r - i][c - i]))
        if starting_point == data[r-i][c-i]:
            size += 1

    for i in range(1, max((len(data) - r), (len(data) - c)), +1):
        if (r - i < 0) or (c - i < 0):
            break
        if starting_point != data[r-i][c+i]:
            break
        print("coor " + str(r - i) + ":" + str(c + i) + " | value " + str(data[r - i][c + i]))
        if starting_point == data[r-i][c+i]:
            size += 1

    for i in range(1, max((len(data) - r), (len(data) - c)), +1):
        if (r - i < 0) or (c - i < 0):
            break
        if starting_point != data[r+i][c-i]:
            break
        print("coor " + str(r + i) + ":" + str(c - i) + " | value " + str(data[r + i][c - i]))
        if starting_point == data[r+i][c-i]:
            size += 1

    return size
