import random


class MyRPSPlayer:
    def __init__(self):
        pass

    def play(self):
        return self.play_random()

    def play_random(self):
        return random.choice(["R", "P", "S"])

if __name__ == "__main__":
    player = MyRPSPlayer()
    for game in range(10):
        print(player.play())
