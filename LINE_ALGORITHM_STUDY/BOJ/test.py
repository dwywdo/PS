import sys
 
left_str = sys.stdin.readline()
M = int(input())

right_str = ""

for _ in range(M):
    command = sys.stdin.readline().split()
    if command[0] == 'L' and len(left_str) > 0:
        right_str = left_str[-1] + right_str
        left_str = left_str[:-1]
    elif command[0] == 'D' and len(right_str) > 0:
        left_str = left_str + right_str[0]
        right_str = right_str[1:]
    elif command[0] == 'B' and len(left_str) > 0:
        left_str = left_str[:-1]
    elif command[0] == 'P':
        left_str = left_str + command[1]

print("answer: " + left_str + right_str)

print("left_str: " + left_str)
print("right_str: " + right_str)