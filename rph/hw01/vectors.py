class MyVector:
	def __init__(self, vector):		# constructor taking 1 parameter
		self.vector = vector
	
	def get_vector(self):			# function that returns vector field
		return self.vector
			
	def __mul__(self, other):		# overloading multiplication to scalar product
		scalar = 0
		for i in range(0, min(len(self.vector), len(other.vector))):
			scalar += self.vector[i] * other.vector[i]
			
		return scalar
		
# can run faster - better cycle?
