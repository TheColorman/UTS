import re

ones_word = {
    1: "one",
    2: "two",
    3: "three",
    4: "four",
    5: "five",
    6: "six",
    7: "seven",
    8: "eigth",
    9: "nine",
}
tens_word = {
    1: "ten",
    2: "twenty",
    3: "thirty",
    4: "forty",
    5: "fifty",
    6: "sixty",
    7: "seventy",
    8: "eighty",
    9: "ninety",
}
teens_word = {
    10: "ten",
    11: "eleven",
    12: "twelve",
    13: "thirteen",
    14: "fourteen",
    15: "fifteen",
    16: "sixteen",
    17: "seventeen",
    18: "eighteen",
    19: "nineteen",
}


def int_to_words(n):
    word = ""
    hundreths = n // 100
    tens = (n // 10) % 10
    ones = n % 10
    teen = n % 100

    if hundreths != 0:
        word += ones_word[hundreths] + " hundred "
        if tens != 0 or ones != 0:
            word += " and "

    if tens > 1:
        word += f" {tens_word[tens]} "

    if tens == 1:
        word += f" {teens_word[teen]} "

    if ones != 0 and tens != 1:
        word += f" {ones_word[ones]} "

    if word == "":
        word = "zero"

    return re.sub(" +", " ", word).strip()


def int_to_roman(num):
    """it's fucking beatiful"""
    word = ""

    while num > 0:
        if num >= 900:
            word += "CM"
            num -= 900
        elif num >= 500:
            word += "D"
            num -= 500
        elif num >= 400:
            word += "CD"
            num -= 400
        elif num >= 100:
            word += "C"
            num -= 100
        elif num >= 90:
            word += "XC"
            num -= 90
        elif num >= 50:
            word += "L"
            num -= 50
        elif num >= 40:
            word += "XL"
            num -= 40
        elif num >= 10:
            word += "X"
            num -= 10
        elif num >= 9:
            word += "IX"
            num -= 9
        elif num >= 5:
            word += "V"
            num -= 5
        elif num >= 4:
            word += "IV"
            num -= 4
        else:
            word += "I"
            num -= 1

    return word


if __name__ == "__main__":
    while (n := int(input("Number: "))) != -1:
        words = int_to_words(n)
        roman = int_to_roman(n)
        print(f"In Words: {words}")
        print(f"In Roman: {roman}")

    print("Done")
