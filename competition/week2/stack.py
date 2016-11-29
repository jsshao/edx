o = open('stack.out', 'w')
with open('stack.in' ,'r') as f:
    n = int(f.readline())
    s = []
    for i in range(n):
        a = f.readline().split()
        if len(a) == 1:
            o.write(s.pop() + '\n')
        else:
            s.append(a[1])


