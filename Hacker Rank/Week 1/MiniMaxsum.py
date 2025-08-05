import math
import os
import random
import re
import sys

def miniMaxSum(arr):
    result = sum(arr)
    min_sum = result - max(arr)
    max_sum = result - min(arr)
    print(f"{min_sum} {max_sum}")

arr = list(map(int, input("").strip().split()))
if len(arr) != 5:
    print("Error")
else:
    miniMaxSum(arr)

