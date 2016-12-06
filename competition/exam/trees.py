with open('trees.in', 'r') as input:
    n = int(input.readline())
    r = n / 2
with open('trees.out', 'w') as output:
  output.write(str(r * (n - r)))
  output.write('\n')
