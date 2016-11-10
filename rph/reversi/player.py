class MyPlayer:
    """Player who is making random moves"""

    def __init__(self, my_color, opponent_color):
        self.name = "maresj29"
        self.my_color = my_color
        self.opponent_color = opponent_color

    def move(self, board):
        get_valid_moves(board)

    def get_valid_moves(self, board):
        pass

    def search_around(self, board):
        pass
        #podle vysledku zavolat search in direction

    def search_in_direction(self, board):