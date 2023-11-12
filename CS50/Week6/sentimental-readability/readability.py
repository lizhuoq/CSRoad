# TODO
from cs50 import get_string


def count_letters(text: str):
    length = len(text)
    checksum = 0
    for i in range(length):
        if text[i] >= "a" and text[i] <= "z":
            checksum += 1
    return checksum


def count_words(text: str):
    return len(text.split())


def count_sentences(text: str):
    length = len(text)
    chars = [".", "?", "!"]
    checksum = 0
    for i in range(length):
        if text[i] in chars:
            checksum += 1
    return checksum


def cal_index(n_letters, n_words, n_sentences):
    L = n_letters / n_words * 100
    S = n_sentences / n_words * 100
    ans = 0.0588 * L - 0.296 * S - 15.8
    return ans


def main():
    text = get_string("Text: ")
    text = text.lower()
    n_letters = count_letters(text)
    n_words = count_words(text)
    n_sentences = count_sentences(text)
    ans = cal_index(n_letters, n_words, n_sentences)
    if ans < 1:
        print("Before Grade 1")
    elif ans >= 16:
        print("Grade 16+")
    else:
        ans = round(ans)
        print(f"Grade {ans}")


main()
