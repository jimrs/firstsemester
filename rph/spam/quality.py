from utils import *
from confmat import *

def quality_score(tp, tn, fp, fn):
    return (tp + tn) / (tp + tn + 10*fp +fn)

def compute_quality_for_corpus(corpus_dir):
    truth_dict = read_classification_from_file(corpus_dir + '/!truth.txt')
    pred_dict = read_classification_from_file(corpus_dir + '/!prediction.txt')

    matrix = BinaryConfusionMatrix(pos_tag='SPAM', neg_tag='OK')
    matrix.compute_from_dicts(truth_dict, pred_dict)

    return quality_score(matrix.tp, matrix.tn, matrix.fp, matrix.fn)
