def is_isogram(string):
    s = string.lower().replace(' ', '').replace('-', '')
    for i in range(0, len(s)-1):
        if s[i] in s[i+1:]:
            return False
    return True
