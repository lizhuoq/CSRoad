# TODO
from cs50 import get_int

height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")


for i in range(height):
    num = i + 1
    print(" " * (height - num), end="")
    print("#" * num + " " * 2 + "#" * num)
