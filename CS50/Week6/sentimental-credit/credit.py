# TODO
from cs50 import get_string
import sys


valid_lens = [13, 15, 16]


def check_length(number: str):
    length = len(number)
    if length not in valid_lens:
        return False
    return True


def check_amex(number: str):
    start = number[:2]
    if start in ["34", "37"]:
        return True
    return False


def check_visa(number: str):
    start = number[:1]
    if start == "4":
        return True
    return False


def check_mastercard(number: str):
    start = int(number[:2])
    if start in list(range(51, 56)):
        return True
    return False


def check_luhn(number: str):
    number = number[::-1]
    checksum = 0
    temp = ""
    for i in range(len(number)):
        if i % 2 == 0:
            checksum += int(number[i])
        else:
            temp += str(2 * int(number[i]))
    temp = sum([int(x) for x in temp])
    checksum += temp
    if checksum % 10 == 0:
        return True
    return False


def check(number: str):
    if not check_length(number):
        return "INVALID"
    if not check_luhn(number):
        return "INVALID"
    if check_amex(number):
        return "AMEX"
    if check_mastercard(number):
        return "MASTERCARD"
    if check_visa(number):
        return "VISA"
    return "INVALID"


def main():
    number = get_string("Number: ")
    print(check(number))


main()
