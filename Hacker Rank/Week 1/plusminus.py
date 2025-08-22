def plusMinus(arr):
    n = len(arr)  
    positive =0
    negative =0
    zero = 0  

    for num in arr:
        if num > 0:
            positive += 1
        elif num < 0:
            negative += 1
        else:
            zero += 1

    print(f"{positive/n:.6f}")
    print(f"{negative/n:.6f}")
    print(f"{zero/n:.6f}")

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    plusMinus(arr)
