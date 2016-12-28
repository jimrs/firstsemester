def read_classification_from_file(file):
    classification = {}

    with open(file, encoding='utf-8') as classification_file:
        for line in classification_file:
            classification_list = line.split()
            classification[classification_list[0]] = classification_list[1]

    return classification
