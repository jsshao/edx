def sieves(n):
    primes = []
    prime = [True for i in range(n)]
    for i in range(2, n):
        if prime[i] == True:
            primes.append(i)
            j = 2*i
            while j < n:
                prime[j] = False
                j += i
    return primes

primes = sieves(24)
hack = [0 for i in range(9)]
cheating = {}

def recurse(hack, k):
    global best_divisors, best, cheating
    for i in range(1, 9):
        if hack[i] > hack[i-1]:
            return
    prod = 1
    divisors = 1
    for i in range(9):
        prod *= primes[i] ** hack[i]
        divisors *= hack[i] + 1
    if prod > k:
        return
    if divisors not in cheating or cheating[divisors] > prod:
        cheating[divisors] = prod
    for i in range(9):
        hack[i] += 1
        recurse(hack, k)
        hack[i] -= 1


with open('testgen.in', 'r') as input:
    k = int(input.readline())
    #recurse(hack, 10000001)
    # Preprocessed using above code
    cheating = {1: 1, 2: 2, 3: 4, 4: 6, 5: 16, 6: 12, 7: 64, 8: 24, 9: 36, 10: 48, 11: 1024, 12: 60, 13: 4096, 14: 192, 15: 144, 16: 120, 17: 65536, 18: 180, 19: 262144, 20: 240, 21: 576, 22: 3072, 23: 4194304, 24: 360, 25: 1296, 26: 12288, 27: 900, 28: 960, 30: 720, 32: 840, 33: 9216, 34: 196608, 35: 5184, 36: 1260, 38: 786432, 39: 36864, 40: 1680, 42: 2880, 44: 15360, 45: 3600, 48: 2520, 49: 46656, 50: 6480, 51: 589824, 52: 61440, 54: 6300, 55: 82944, 56: 6720, 57: 2359296, 60: 5040, 63: 14400, 64: 7560, 65: 331776, 66: 46080, 68: 983040, 70: 25920, 72: 10080, 75: 32400, 76: 3932160, 77: 746496, 78: 184320, 80: 15120, 81: 44100, 84: 20160, 85: 5308416, 88: 107520, 90: 25200, 91: 2985984, 96: 27720, 98: 233280, 99: 230400, 100: 45360, 102: 2949120, 104: 430080, 105: 129600, 108: 50400, 110: 414720, 112: 60480, 117: 921600, 120: 55440, 125: 810000, 126: 100800, 128: 83160, 130: 1658880, 132: 322560, 135: 176400, 136: 6881280, 140: 181440, 144: 110880, 147: 1166400, 150: 226800, 154: 3732480, 156: 1290240, 160: 166320, 162: 352800, 165: 2073600, 168: 221760, 175: 3240000, 176: 967680, 180: 277200, 189: 705600, 192: 332640, 195: 8294400, 196: 1632960, 198: 1612800, 200: 498960, 208: 3870720, 210: 907200, 216: 554400, 220: 2903040, 224: 665280, 225: 1587600, 234: 6451200, 240: 720720, 243: 2822400, 250: 5670000, 252: 1108800, 256: 1081080, 264: 3548160, 270: 1940400, 280: 1995840, 288: 1441440, 294: 8164800, 300: 2494800, 315: 6350400, 320: 2162160, 324: 3880800, 336: 2882880, 360: 3603600, 378: 7761600, 384: 4324320, 400: 6486480, 420: 9979200, 432: 7207200, 448: 8648640}
    best = 1
    best_num = 1
    for divisors in cheating:
        if cheating[divisors] <= k and divisors > best:
            best = divisors
            best_num = cheating[divisors]

with open('testgen.out', 'w') as output:
    output.write(str(k - best_num + 1) + '\n')
