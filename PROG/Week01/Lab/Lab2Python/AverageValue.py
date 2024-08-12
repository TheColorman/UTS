tot = 0
cnt = 0

val = int(input("Value: "))
while val != -1:
	tot += val
	cnt += 1
	val = int(input("Value: "))

if cnt != 0: print(f"Average = {tot/cnt:.1f}")