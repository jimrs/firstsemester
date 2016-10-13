def find_max(in_list):
	"""
    find maximum value in a list or tuple
    :param in_list: a list or tuple of elements that allow < comparison
    :return: a tuple max_value, index of the max_value within the list
    """
    
	if not(in_list):			# if the list is empty, not returns true and code under if is done
		return None
		
	max_value = in_list[0]
	max_value_index = 0
	
	for i in range(0, len(in_list)):
		comparable = in_list[i]
		
		if comparable > max_value:
			max_value = comparable
			max_value_index = i
	
	return (max_value, max_value_index)
