public class CountVowels {
	public static void main(String[] args) {
		int cnt = 0;
		
		System.out.print("Character: ");
		char chr = In.nextChar();
		
		while (chr != '.') {
			if ("aeiou".indexOf(chr) != -1)
				cnt++;
			System.out.print("Character: ");
			chr = In.nextChar();
		}
		
		System.out.println("Vowel count = " + cnt);
	}
}
