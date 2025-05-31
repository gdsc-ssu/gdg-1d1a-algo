n = int(input())

brackets = []
for _ in range(n):
    brackets.append(input())

for bracket in brackets:
    stack = []
    bracket_len = len(bracket)
    cnt = 0
    for b in bracket:
        if b == "(":
            stack.append("(")
        else:
            if stack:
                stack.pop()
            else:
                break
        cnt += 1

    if not stack and cnt == bracket_len:
        print('YES')
    else:
        print('NO')