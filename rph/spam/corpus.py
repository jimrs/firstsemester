import os

class Corpus:
    def __init__(self, directory):
        self.dir = directory

    def emails(self):
        for file in os.listdir(self.dir):
            if file.startswith("!"):
                pass
            else:
                yield file

if __name__ == "__main__":
    corpus = Corpus('1/')
    count = 0
    for fname in corpus.emails():
        print(fname)
        count += 1
    print('Finished: ', count, 'files processed.')
