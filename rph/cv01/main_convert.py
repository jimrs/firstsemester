import converter

goodboi = 0

while goodboi == 0:
	choice = raw_input("Enter 'C' for converting C to F, enter 'F' for converting F to C: ")
	if choice == "C":
		c = input("Enter an integer for Celsius: ")
		f = converter.temp_c_to_f(c)
		print(str(c) + "C is " + str(f) + "F.")
		goodboi = 1

	elif choice == "F":
		f = input("Enter an integer for Fahrenheit: ")
		c = converter.temp_f_to_c(f)
		print(str(f) + "F is " + str(c) + "C.")
		goodboi = 1
	
	else:
		print("You chose wrong. Do it again.")
		
