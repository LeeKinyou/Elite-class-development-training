import math

p = eval(input())
num = int(math.log10(2**p - 1)) + 1
d500 = str(2 ** p - 1)[-500:]
print(num)
if num < 500:
    d500 = d500.zfill(500)

num_lines = len(d500) // 50
if len(d500) % 50 != 0:
    num_lines += 1

for i in range(num_lines):
    line = d500[i * 50 : (i + 1) * 50]
    print(line)
