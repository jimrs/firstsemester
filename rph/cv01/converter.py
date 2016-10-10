def temp_c_to_f(c):
	f = (1.8 * c) + 32
	return(f)

def temp_f_to_c(f):
	c = (f - 32) / 1.8
	return(c)
	
if __name__ == "__main__":
	for c in [-10,-5,0,5,10,20,30]:
		f = temp_c_to_f(c)
		print(str(c) + "C is exactly " + str(f) + "F.")
