class Cuboid:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def compute_volume(self):
        volume = self.a * self.b * self.c
        return volume

    def make_scaled_copy(self, scale):
        return Cuboid(self.a * scale, self.b * scale, self.c * scale)

if __name__ == "__main__":
    c1 = Cuboid(1, 2, 3)
    print(c1.compute_volume())
    c3 = c1.make_scaled_copy(2)
    print(type(c3))
    print(c3.compute_volume())
