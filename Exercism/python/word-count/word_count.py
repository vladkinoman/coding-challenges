from curses.ascii import *

def count_words(sentence):
    result_dict = {}
    word = ''
    for i in range(0, len(sentence)):
        if not ispunct(sentence[i]) and not isspace(sentence[i]) or sentence[i]=="'":
            word += sentence[i]
        elif word != '':
            result_dict[word] = 0
            word = ''
    for key in result_dict.keys():
            result_dict[key] = sentence.count(key)
    return result_dict
