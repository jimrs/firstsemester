import random

class MyPlayer:
    """Player who is making random moves"""

    def __init__(self, my_color, opponent_color):
        self.name = "maresj29"
        self.my_color = my_color
        self.opponent_color = opponent_color

    def move(self, board):
        my_stones = self.get_my_stones(board)
        print(*my_stones)

        end_points = self.search_around_my_stones(board, my_stones)
        print(*end_points)

        valid_moves = self.get_valid_moves(board, end_points)
        print(*valid_moves)

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
        direction = 0  # 0deg, 45, 90, 135, 180, 225, 270, 315, 360

        for stone in my_stones:  # direction 0 >>>>>>
            try:
                for i in range(1, 8):
                    if (board[stone[0]][stone[1] + i] != self.opponent_color):
                        if end_point == (-1, -1, 0):
                            break
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
                    else:
                        end_point = (stone[0], stone[1] + i, direction)
                    if i == 7:
                        if end_point == (-1, -1, 0):
                            pass
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
            except:
                if end_point == (-1, -1, 0):
                    pass
                else:
                    end_points_of_directions.append(end_point)
                    end_point = (-1, -1, 0)
        direction += 45

        for stone in my_stones:  # direction 45 >^>^>^
            try:
                for i in range(1, 8):
                    if (board[stone[0] - i][stone[1] + i] != self.opponent_color):
                        if end_point == (-1, -1, 0):
                            break
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
                    else:
                        end_point = (stone[0] - i, stone[1] + i, direction)
                    if i == 7:
                        if end_point == (-1, -1, 0):
                            pass
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
            except:
                if end_point == (-1, -1, 0):
                    pass
                else:
                    end_points_of_directions.append(end_point)
                    end_point = (-1, -1, 0)
        direction += 45

        for stone in my_stones:  # direction 90 ^^^^^^
            try:
                for i in range(1, 8):
                    if (board[stone[0] - i][stone[1]] != self.opponent_color):
                        if end_point == (-1, -1, 0):
                            break
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
                    else:
                        end_point = (stone[0] - i, stone[1], direction)
                    if i == 7:
                        if end_point == (-1, -1, 0):
                            pass
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
            except:
                if end_point == (-1, -1, 0):
                    pass
                else:
                    end_points_of_directions.append(end_point)
                    end_point = (-1, -1, 0)
        direction += 45

        for stone in my_stones:  # direction 135 <^<^<^
            try:
                for i in range(1, 8):
                    if (board[stone[0] - i][stone[1] - i] != self.opponent_color):
                        if end_point == (-1, -1, 0):
                            break
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
                    else:
                        end_point = (stone[0] - i, stone[1] - i, direction)
                    if i == 7:
                        if end_point == (-1, -1, 0):
                            pass
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
            except:
                if end_point == (-1, -1, 0):
                    pass
                else:
                    end_points_of_directions.append(end_point)
                    end_point = (-1, -1, 0)
        direction += 45

        for stone in my_stones:  # direction 180 <<<<<<
            try:
                for i in range(1, 8):
                    if (board[stone[0]][stone[1] - i] != self.opponent_color):
                        if end_point == (-1, -1, 0):
                            break
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
                    else:
                        end_point = (stone[0], stone[1] - i, direction)
                    if i == 7:
                        if end_point == (-1, -1, 0):
                            pass
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
            except:
                if end_point == (-1, -1, 0):
                    pass
                else:
                    end_points_of_directions.append(end_point)
                    end_point = (-1, -1, 0)
        direction += 45

        for stone in my_stones:  # direction 225 v<v<v<
            try:
                for i in range(1, 8):
                    if (board[stone[0] + i][stone[1] - i] != self.opponent_color):
                        if end_point == (-1, -1, 0):
                            break
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
                    else:
                        end_point = (stone[0] + i, stone[1] - i, direction)
                    if i == 7:
                        if end_point == (-1, -1, 0):
                            pass
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
            except:
                if end_point == (-1, -1, 0):
                    pass
                else:
                    end_points_of_directions.append(end_point)
                    end_point = (-1, -1, 0)
        direction += 45

        for stone in my_stones:  # direction 270 vvvvvv
            try:
                for i in range(1, 8):
                    if (board[stone[0] + 1][stone[1]] != self.opponent_color):
                        if end_point == (-1, -1, 0):
                            break
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
                    else:
                        end_point = (stone[0] + i, stone[1], direction)
                    if i == 7:
                        if end_point == (-1, -1, 0):
                            pass
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
            except:
                if end_point == (-1, -1, 0):
                    pass
                else:
                    end_points_of_directions.append(end_point)
                    end_point = (-1, -1, 0)
        direction += 45

        for stone in my_stones:  # direction 315 ^^^^^^
            try:
                for i in range(1, 8):
                    if (board[stone[0] + i][stone[1] + i] != self.opponent_color):
                        if end_point == (-1, -1, 0):
                            break
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
                    else:
                        end_point = (stone[0] + i, stone[1] + i, direction)
                    if i == 7:
                        if end_point == (-1, -1, 0):
                            pass
                        else:
                            end_points_of_directions.append(end_point)
                            end_point = (-1, -1, 0)
            except:
                if end_point == (-1, -1, 0):
                    pass
                else:
                    end_points_of_directions.append(end_point)
                    end_point = (-1, -1, 0)
        direction += 45

        return end_points_of_directions

    def get_valid_moves(self, board, end_points):
        valid_moves = []

        for i in range(0, len(end_points)):
            if end_points[i][2] == 0:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        pass
                    elif end_points[i][1] + 1 > 7:
                        pass
                    else:
                        valid_moves.append((end_points[i][0], end_points[i][1] + 1))
                except:
                    pass

            if end_points[i][2] == 45:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        pass
                    elif end_points[i][1] + 1 > 7:
                        pass
                    elif (end_points[i][0] - 1 < 0):
                        pass
                    else:
                        valid_moves.append((end_points[i][0] - 1, end_points[i][1] + 1))
                except:
                    pass

            if end_points[i][2] == 90:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        pass
                    elif (end_points[i][0] - 1 < 0):
                        pass
                    else:
                        valid_moves.append((end_points[i][0] - 1, end_points[i][1]))
                except:
                    pass

            if end_points[i][2] == 135:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        pass
                    elif (end_points[i][0] - 1 < 0 or end_points[i][1] - 1 < 0):
                        pass
                    else:
                        valid_moves.append((end_points[i][0] - 1, end_points[i][1] - 1))
                except:
                    pass

            if end_points[i][2] == 180:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        pass
                    elif (end_points[i][1] - 1 < 0):
                        pass
                    else:
                        valid_moves.append((end_points[i][0], end_points[i][1] - 1))
                except:
                    pass

            if end_points[i][2] == 225:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        pass
                    elif end_points[i][0] + 1 > 7:
                        pass
                    elif (end_points[i][1] - 1 < 0):
                        pass
                    else:
                        valid_moves.append((end_points[i][0] + 1, end_points[i][1] - 1))
                except:
                    pass

            if end_points[i][2] == 270:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        pass
                    elif end_points[i][0] + 1 > 7:
                        pass
                    else:
                        valid_moves.append((end_points[i][0] + 1, end_points[i][1]))
                except:
                    pass

            if end_points[i][2] == 315:
                try:
                    if end_points[i][0] > 7 or end_points[i][1] > 7:
                        pass
                    elif end_points[i][0] + 1 > 7:
                        pass
                    elif end_points[i][1] + 1 > 7:
                        pass
                    else:
                        valid_moves.append((end_points[i][0] + 1, end_points[i][1] + 1))
                except:
                    pass

        for i in range(0, 8):
            for j in range(0, 8):
                try:
                    if board[i][j] != -1:
                        valid_moves = list(filter((i, j).__ne__, valid_moves))
                except:
                    pass

        return valid_moves


if __name__ == "__main__":
    player = MyPlayer(1, 0)
    board = [[-1, -1, -1, -1, -1, -1, -1, -1], [-1, -1, -1, -1, -1, -1, -1, -1], [-1, -1, -1, -1, -1, -1, -1, -1],
             [-1, -1, -1, 0, 1, -1, -1, -1], [-1, -1, -1, 1, 0, -1, -1, -1], [-1, -1, -1, -1, -1, -1, -1, -1],
             [-1, -1, -1, -1, -1, -1, -1, -1], [-1, -1, -1, -1, -1, -1, -1, -1]]

    player.move(board)
