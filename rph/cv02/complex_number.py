class ComplexNumber:
	def __init__(self, re = 0, im = 0):	# defining constructor
		self.re = re
		self.im = im

	def __add__(self, other):	# adding function overload
		return ComplexNumber(self.re + other.re, self.im + other.im)

	def __str__(self):	# string function overload
		#return "Complex number: " + str(self.re) + ", " + str(self.im)
		return "(" + str(self.re) + ", " + str(self.im) + ")"

if __name__ == "__main__":
	a = ComplexNumber(1,2)
	b = ComplexNumber(10,10)
	c = a+b

	print(a.re, a.im)
	print(c)
