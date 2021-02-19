def convert(number):
    s_result=""
    if number % 3 == 0:
        s_result += "Pling"
    if number % 5 == 0:
        s_result += "Plang"
    if number % 7 == 0:
        s_result += "Plong"
    if s_result == "":
        s_result = str(number)
    return s_result
