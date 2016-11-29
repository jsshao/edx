
def dist(a, b):
    return max(abs(a[0] - b[0]), abs(a[1] - b[1]))

with open('template.in', 'r') as input:
    w, h = map(int, input.readline().split())
    hack = {}
    for i in range(h):
        line = input.readline()
        for j in range(len(line)):
            c = line[j]
            if c == '\n':
                continue
            hack[c] = (i, j)
    input.readline()
    line = input.readline()
    best = ""
    best_score = None
    while line != "":
        lang = line.strip()
        score = 0
        line = input.readline()
        last = line[0]
        while line != '\n':
            for i in line:
                if i == '\n':
                    continue
                score += dist(hack[last], hack[i])
                last = i
            line = input.readline()
        if best_score is None or score < best_score:
            best = lang
            best_score = score
        line = input.readline()
                

with open('template.out', 'w') as output:
    output.write(best + '\n' + str(best_score) + '\n')
