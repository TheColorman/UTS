if __name__ == '__main__':
	vowel_count = 0
	
	while True:
		char = input("Character: ")
		if char == ".": break
		if char in "aeiou": vowel_count += 1
	
	print(f"Vowel count = {vowel_count}")