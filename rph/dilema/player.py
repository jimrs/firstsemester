class MyPlayer:
    """Hello this is my good player it returns nice values like true or false ok thanks"""

    def __init__(self, payoff_matrix, number_of_iterations=0):
        self.payoff_matrix = payoff_matrix
        self.number_of_iterations = number_of_iterations    # due to my simple strategy, this value remains unused
        self.played = 0
        self.memory = []
        self.matrix_analysis = None

        self.matrix_analysis = self.analyze_matrix(payoff_matrix)
        self.strategy = self.pick_strategy(self.matrix_analysis)

    def move(self):
        self.played += 1
        if self.played < 4:                     # for first 3 moves, always returns the same
            if self.strategy == "alwaysD":
                return True
            if self.strategy == "alwaysC":
                return False
            if self.strategy == "classic":
                return False
            if self.strategy == "alwaysCwatchforD":
                return False
            if self.strategy == "alwaysDwatchforC":
                return True

        else:
            opponent_analysis = self.analyze_opponent(self.memory)      # begin analyzing the opponent and take his moves into consideration

            if self.strategy == "classic":
                if opponent_analysis == "cooperating":
                    return False
                if opponent_analysis == "defected":
                    return False
                if opponent_analysis == "defective":
                    return False
                if opponent_analysis == "defecting":
                    return True
            if self.strategy == "alwaysCwatchforD":
                if opponent_analysis == "cooperating":
                    return False
                if opponent_analysis == "defected":
                    return False
                if opponent_analysis == "defective":
                    return False
                if opponent_analysis == "defecting":
                    return True
            if self.strategy == "alwaysDwatchforC":
                if opponent_analysis == "cooperating":
                    return False
                if opponent_analysis == "defected":
                    return True
                if opponent_analysis == "defective":
                    return True
                if opponent_analysis == "defecting":
                    return True
            if self.strategy == "alwaysD":
                return True
            if self.strategy == "alwaysC":
                return False

    def record_opponents_move(self, opponent_move):
        if opponent_move:
            self.memory.append(1)   # if opponent defects, append 1 to memory
        else:
            self.memory.append(0)   # if opponent cooperates, append 0 to memory

    def analyze_matrix(self, payoff_matrix):
        cc = payoff_matrix[0][0][0]
        dc = payoff_matrix[1][0][0]
        dd = payoff_matrix[1][1][0]

        if dc >= cc:                # a simple analysis based on the most profitable to least
            if cc >= dd:
                return "classic"    # dc_cc_dd
            else:
                return "dc_dd_cc"

        if cc >= dc:
            if dc >= dd:
                return "cc_dc_dd"
            else:
                return "cc_dd_dc"

        if dd >= cc:
            if dc >= cc:
                return "dd_dc_cc"
            else:
                return "dd_cc_dc"

    def analyze_opponent(self, memory_array):
        last_three_moves = memory_array[-3:0]   # takes the last 3 items of memory array
        if sum(last_three_moves) == 0:          # by evaluating a sum, there is a tolerance for accidental noise
            return "cooperating"
        if sum(last_three_moves) == 1:
            return "defected"
        if sum(last_three_moves) == 2:
            return "defective"
        if sum(last_three_moves) == 3:
            return "defecting"

    def pick_strategy(self, matrix_analysis):   # choose the most profitable strategy based on matrix analysis
        if matrix_analysis == "dc_dd_cc":
            return "alwaysD"
        if matrix_analysis == "dd_dc_cc":
            return "alwaysD"
        if matrix_analysis == "cc_dc_dd":
            return "alwaysC"
        if matrix_analysis == "classic":
            return "classic"
        if matrix_analysis == "cc_dd_dc":
            return "alwaysCwatchforD"
        if matrix_analysis == "dd_cc_dc":
            return "alwaysDwatchforC"
