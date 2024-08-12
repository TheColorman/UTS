def main():
	integers = []
	
	while True:
		val = int(input("Enter an integer (-1 to exit): "))
		if val == -1: break
		integers.append(val)
	
	if len(integers) < 4:
		return print("No average to display.")
	
	originalSum = sum(integers)

	integers.sort()
	integers = integers[1:-1]

	avg = sum(integers) / len(integers)
	isDivByCount = originalSum % (len(integers) + 2) == 0
	print(f"The middle average is: {avg}")
	if isDivByCount: print("The sum is divisible by count")
	else: print("The sum is not divisible by count")

if __name__ == '__main__':
	main()