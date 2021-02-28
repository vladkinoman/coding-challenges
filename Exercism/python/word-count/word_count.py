from curses.ascii import isalnum
from curses.ascii import isalpha

def count_words(sentence):
    n = len(sentence)
    s = sentence[0:n]
    #s.lower()
    result_dict = {}
    # processing
    i = 0
    while i < n:
        if not isalnum(s[i]) and s[i] != ' ' and s[i] != '\n' and s[i] != '\t':
            if i == 0:
                s = s[1:]
            elif i == n-1:
                s = s[0:i]
            else:
                if s[i] == '\'' and isalpha(s[i-1]) and isalpha(s[i+1]):
                    # do nothing, this is an apostroph
                    i += 1
                else:
                    s = s[:i] + s[i+1:]
            n = len(s)
        else: 
            i += 1
    # parsing
    
    # searching
    
    return s