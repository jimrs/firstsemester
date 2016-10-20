class MyPlayer:
    """A simple player who always defects"""

    def __init__(self, payoff_matrix, number_of_iterations = 0):
        self.payoff_matrix = payoff_matrix
        self.number_of_iterations = number_of_iterations

    def move(self):
        return True;    #number that keeps adding up representing number of moves?

    def record_opponents_move(self, opponent_move):
        pass    #add to an array = memory

    def analyze_matrix(self, payoff_matrix):
        pass    #returns a value representing best strategy

    def analyze_opponent(self, memory_array):
        pass    #analyzes behavior of opponent and returns a value representing his type

    def pick_strategy(self, matrix_analysis, opponent_analysis):
        pass    #case switch for each possible combination
