from corpus import *

class MyFilter:
    def train(self, dir):
        pass

    def test(self, dir):
        corpus = Corpus(dir)

        with open(dir + '/!prediction.txt', 'w', encoding='utf-8') as f:
            for mail in corpus.emails():
                line = mail + ' OK\n'
                f.write(line)
