def timeConversion(s):
    period = s[-2:]
    h, m, ss = s[:-2].split(':')
    h = int(h)
    if period == 'AM':
        if h == 12:
            h = 0
    else:
        if h != 12:
            h += 12
    return f"{h:02}:{m}:{ss}"
s = input()
print(timeConversion(s))
