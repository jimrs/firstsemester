def count_rows_and_words(filename):
    rows = 0
    words = 0

    with open(filename, 'r', encoding='utf-8') as f:
        for line in f:
            rows += 1

        for line in f:
            line = line.split()

            for word in line:
                words += 1

    return (rows, words)

def compute_word_frequencies(filename):
    
    words = {}

    with open(filename, 'r', encoding='utf-8') as f:
        for line in f:
            line = line.split()

            for word in line:
                words[word] = words.get (word, 0) + 1

    return words
