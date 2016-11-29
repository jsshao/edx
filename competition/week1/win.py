with open('win.in', 'r') as input:
    n = int(input.readline())
    l = [int(i) for i in input.readline().split()]
    l.sort()
    ans = 0
    num = 0
    for i in l:
        if ans + i <= 300 * 60:
            num += 1
            ans += i
with open('win.out', 'w') as output:
    output.write(str(num) + '\n')
