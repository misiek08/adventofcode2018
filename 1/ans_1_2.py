import sys

lines = open(sys.argv[1]).readlines()
lines = [line.rstrip('\n') for line in lines][:-1]
state = 0
it = 0
seen = dict()

while not seen.get(state, False):
    seen[state] = True
    state += int(lines[it])
    it += 1
    if it >= len(lines):
        it = 0


print('result', state)
