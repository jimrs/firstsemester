import random

class MyPlayer:
    """Player who is making random moves"""

    def __init__(self, my_color, opponent_color):
        self.name = "maresj29"
        self.my_color = my_color
        self.opponent_color = opponent_color

    def move(self, board):
        my_stones = self.get_my_stones(board)

        end_points = self.search_around_my_stones(board, my_stones)

        valid_moves = self.get_valid_moves(board, end_points)

        if len(valid_moves) == 0:
            return None
        else:
            index = random.randint(0, len(valid_moves) - 1)
            return valid_moves[index]

    def get_my_stones(self, board):
        my_stones = []

        for row in range(0, 8):
            for col in range(0, 8):
                if board[row][col] == self.my_color:
                    my_stones.append((row, col))

        return my_stones

    def search_around_my_stones(self, board, my_stones):
        end_points_of_directions = []
        end_point = (-1, -1, 0)
        direction = 0  # 0deg, 45, 90, 135, 180, 225, 270, 315

        for stone in my_stones:  # direction 0 >>>>>>
            x = stone[0]
            y = stone[1]

            try:
                for i in range(1, 8):
                    if (board[x][y + i] != self.opponent_color):
                        end_points_of_directions.append(end_point)
                        break
                    else:
                        end_point = (x, y + i, direction)   # vrati i hrany!
                    if i == 7:
                        end_points_of_directions.append(end_point)
            except:
                end_points_of_directions.append(end_point)

        direction += 45
        end_point = (-1, -1, 0)


        for stone in my_stones:  # direction 45 >^>^>^
            x = stone[0]
            y = stone[1]
            
            try:
                for i in range(1, 8):
                    if (board[x - i][y + i] != self.opponent_color):
                        end_points_of_directions.append(end_point)
                        break
                    else:
                        end_point = (x - i, y + i, direction)
                    if i == 7:
                        end_points_of_directions.append(end_point)
            except:
                end_points_of_directions.append(end_point)

        direction += 45
        end_point = (-1, -1, 0)

        for stone in my_stones:  # direction 90 ^^^^^^
            x = stone[0]
            y = stone[1]

            try:
                for i in range(1, 8):
                    if (board[x - i][y] != self.opponent_color):
                        end_points_of_directions.append(end_point)
                        break
                    else:
                        end_point = (x - i, y, direction)
                    if i == 7:
                        end_points_of_directions.append(end_point)
            except:
                end_points_of_directions.append(end_point)

        direction += 45
        end_point = (-1, -1, 0)

        for stone in my_stones:  # direction 135 <^<^<^
            x = stone[0]
            y = stone[1]

            try:
                for i in range(1, 8):
                    if (board[x - i][y - i] != self.opponent_color):
                        end_points_of_directions.append(end_point)
                        break
                    else:
                        end_point = (x - i, y - i, direction)
                    if i == 7:
                        end_points_of_directions.append(end_point)
            except:
                end_points_of_directions.append(end_point)

        direction += 45
        end_point = (-1, -1, 0)

        for stone in my_stones:  # direction 180 <<<<<<
            x = stone[0]
            y = stone[1]

            try:
                for i in range(1, 8):
                    if (board[x][y - i] != self.opponent_color):
                        end_points_of_directions.append(end_point)
                        break
                    else:
                        end_point = (x, y - i, direction)
                    if i == 7:
                        end_points_of_directions.append(end_point)
            except:
                end_points_of_directions.append(end_point)

        direction += 45
        end_point = (-1, -1, 0)

        for stone in my_stones:  # direction 225 v<v<v<
            x = stone[0]
            y = stone[1]

            try:
                for i in range(1, 8):
                    if (board[x + i][y - i] != self.opponent_color):
                        end_points_of_directions.append(end_point)
                        break
                    else:
                        end_point = (x + i, y - i, direction)
                    if i == 7:
                        end_points_of_directions.append(end_point)
            except:
                end_points_of_directions.append(end_point)

        direction += 45
        end_point = (-1, -1, 0)

        for stone in my_stones:  # direction 270 vvvvvv
            x = stone[0]
            y = stone[1]

            try:
                for i in range(1, 8):
                    if (board[x + i][y] != self.opponent_color):
                        end_points_of_directions.append(end_point)
                        break
                    else:
                        end_point = (x + i, y, direction)
                    if i == 7:
                        end_points_of_directions.append(end_point)
            except:
                end_points_of_directions.append(end_point)

        direction += 45
        end_point = (-1, -1, 0)

        for stone in my_stones:  # direction 315 v>v>v>
            x = stone[0]
            y = stone[1]

            try:
                for i in range(1, 8):
                    if (board[x + i][y + i] != self.opponent_color):
                        end_points_of_directions.append(end_point)
                        break
                    else:
                        end_point = (x + i, y + i, direction)
                    if i == 7:
                        end_points_of_directions.append(end_point)
            except:
                end_points_of_directions.append(end_point)

        end_points_of_directions = list(filter((-1, -1, 0).__ne__, end_points_of_directions))
        # remove all occurences of (-1, -1, 0)

        end_points_no_duplicates = []
        for item in end_points_of_directions:
            if item not in end_points_no_duplicates:
                end_points_no_duplicates.append(item)

        return end_points_no_duplicates

    def get_valid_moves(self, board, end_points):
        valid_moves = []

        for i in range(0, len(end_points)):
            if end_points[i][2] == 0:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        continue
                    elif end_points[i][1] + 1 > 7:
                        continue
                    else:
                        valid_moves.append((end_points[i][0], end_points[i][1] + 1))
                except:
                    continue

            if end_points[i][2] == 45:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        continue
                    elif end_points[i][1] + 1 > 7:
                        continue
                    elif (end_points[i][0] - 1 < 0):
                        continue
                    else:
                        valid_moves.append((end_points[i][0] - 1, end_points[i][1] + 1))
                except:
                    continue

            if end_points[i][2] == 90:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        continue
                    elif (end_points[i][0] - 1 < 0):
                        continue
                    else:
                        valid_moves.append((end_points[i][0] - 1, end_points[i][1]))
                except:
                    continue

            if end_points[i][2] == 135:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        continue
                    elif (end_points[i][0] - 1 < 0 or end_points[i][1] - 1 < 0):
                        continue
                    else:
                        valid_moves.append((end_points[i][0] - 1, end_points[i][1] - 1))
                except:
                    continue

            if end_points[i][2] == 180:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        continue
                    elif (end_points[i][1] - 1 < 0):
                        continue
                    else:
                        valid_moves.append((end_points[i][0], end_points[i][1] - 1))
                except:
                    continue

            if end_points[i][2] == 225:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        continue
                    elif end_points[i][0] + 1 > 7:
                        continue
                    elif (end_points[i][1] - 1 < 0):
                        continue
                    else:
                        valid_moves.append((end_points[i][0] + 1, end_points[i][1] - 1))
                except:
                    continue

            if end_points[i][2] == 270:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        continue
                    elif end_points[i][0] + 1 > 7:
                        continue
                    else:
                        valid_moves.append((end_points[i][0] + 1, end_points[i][1]))
                except:
                    continue

            if end_points[i][2] == 315:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        continue
                    elif end_points[i][0] + 1 > 7:
                        continue
                    elif end_points[i][1] + 1 > 7:
                        continue
                    else:
                        valid_moves.append((end_points[i][0] + 1, end_points[i][1] + 1))
                except:
                    continue

        for i in range(0, 8):
            for j in range(0, 8):
                try:
                    if board[i][j] != -1:
                        valid_moves = list(filter((i, j).__ne__, valid_moves))  # will remove all occurences of (i, j)
                except:
                    continue


        valid_moves_no_duplicates = []
        for item in valid_moves:
            if item not in valid_moves_no_duplicates:
                valid_moves_no_duplicates.append(item)

        return valid_moves_no_duplicates

    def isValid(self, move, valid_moves):
        if move in valid_moves:
            return True
        else:
            return False
