from collections import deque

n = int(input())
d = deque()
for i in range(n):
  d.append(i + 1)

for i in range(n - 1):
  d.remove(d[0])
  d.append(d[0])
  d.remove(d[0])

print(d[0])
