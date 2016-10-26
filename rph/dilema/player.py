class MyPlayer:
    """Stop illegal immigration to white Europe"""

    def __init__(self, payoff_matrix, number_of_iterations = 0):
        self.payoff_matrix = payoff_matrix
        self.number_of_iterations = number_of_iterations
        self.played = 0
        self.memory = []

        matrix_analysis = self.analyze_matrix(payoff_matrix)
        self.strategy = self.pick_strategy(matrix_analysis)

    def move(self): #sem dat jeste analyze opponent
        if self.strategy == 1:
            return True
        if self.strategy == 0:
            return False
        if self.strategy == 2:
            return False
        if self.strategy == 3:
            return False

        self.played += 1

    def record_opponents_move(self, opponent_move):
        if opponent_move:
            self.memory.extend("D")
        else:
            self.memory.extend("C")

    def analyze_matrix(self, payoff_matrix):
        cc = payoff_matrix[0][0][0]
        dc = payoff_matrix[1][0][0]
        dd = payoff_matrix[1][1][0]

        if dc > cc:
            if cc > dd:
                return "backstab"   #make it look like C but sneakily try D
            else:
                return "allnaughty" #always D

        if cc > dc:
            if dc > dd:
                return "allnice"    #always C
            else:
                return "reversebackstab"    #try to C, but if opponent D then D too

        if dd > cc:
            if dc > cc:
                return "allnaughty"
            else:
                return "allnaughty"

    def analyze_opponent(self, memory_array):
        pass # analyzovat posledni 3/2/1?

    def pick_strategy(self, matrix_analysis, opponent_analysis = None):
        if self.played == 0:
            if matrix_analysis == "allnaughty":
                return 1
            if matrix_analysis == "allnice":
                return 0
            if matrix_analysis == "backstab":
                return 2
            if matrix_analysis == "reversebackstab":
                return 3
        else: #sem psat pripady s opponent analysis
            pass
