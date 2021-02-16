def two_fer(name=None):
    you = "you"
    if name != None:
        you = name
    return "One for {}, one for me.".format(you)
