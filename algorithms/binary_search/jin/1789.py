n = int(input())
result=0
cnt =0 
foo = 1

while result <n:
  result +=foo
  cnt+=1
  foo+=1

print(cnt-1)
