from curses.ascii import isalnum
from curses.ascii import isalpha
from curses.ascii import isspace

def count_words(sentence):
    n = len(sentence)
    # parsing
    s = sentence[0:n].lower()
    i = 0
    while i < n:
        if not isalnum(s[i]) and not isspace(s[i]):
            if i == 0:
                s = s[i+1:]
            elif i == n-1:
                s = s[0:i]
            elif s[i] == '\'' and isalpha(s[i-1]) and isalpha(s[i+1]):
                i += 1
            else:
                s = s[:i] + " " + s[i+1:]
        elif isspace(s[i]):
            if isspace(s[i-1]):
                # there can only be one space between words
                s = s[:i] + s[i+1:]
            elif isalnum(s[i-1]) and s[i] != ' ' :
                # this will make it easier to split the lines
                s = s[:i] + " " + s[i+1:]
            else:    
                i += 1
        else: 
            i += 1
        n = len(s)
    parsed_l = s.strip().split(' ')
    # searching
    counts = dict()
    for i in parsed_l:
        counts[i] = counts.get(i, 0) + 1
    return counts