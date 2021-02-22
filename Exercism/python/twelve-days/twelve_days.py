def recite(start_verse, end_verse):
    days = [
        "", "first", "second", "third", "fourth", "fifth", "sixth",
        "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"
    ]
    presents = [
        "a Partridge in a Pear Tree.",
        "and a Partridge in a Pear Tree.",
        "two Turtle Doves, ",
        "three French Hens, ",
        "four Calling Birds, ",
        "five Gold Rings, ",
        "six Geese-a-Laying, ",
        "seven Swans-a-Swimming, ",
        "eight Maids-a-Milking, ",
        "nine Ladies Dancing, ",
        "ten Lords-a-Leaping, ",
        "eleven Pipers Piping, ",
        "twelve Drummers Drumming, "
    ]
    when = "On the {} day of Christmas my true love gave to me: "

    lyrics = []
    if start_verse == 1:
        lyrics.append(when.format(days[start_verse]) + presents[0])
        start_verse += 1

    for i in range(start_verse, end_verse+1):
        formatted_when = when.format(days[i])
        for j in range(i, 0, -1):
            formatted_when += presents[j]
        lyrics.append(formatted_when)

    return lyrics
