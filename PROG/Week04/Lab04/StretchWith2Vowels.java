public class StretchWith2Vowels {
    static String[] readSentence() {
        System.out.print("Sentence: ");
        String s = In.nextLine().toLowerCase();
        s = s.replaceAll("\\s+", " ");
        return s.split(" ");
    }

    static boolean Contains(String[] array, String target) {
        for (String string : array) {
            if (string.equals(target))
                return true;
        }
        return false;
    }

    static String[] vowels = { "a", "e", "i", "o", "u" };

    static boolean isVowel(String c) {
        return Contains(vowels, c);
    }

    static int countVowels(String segment) {
        String[] letters = segment.split("(?!^)");

        int sum = 0;
        for (String letter : letters) {
            sum += isVowel(letter) ? 1 : 0;
        }

        return sum;
    }

    static boolean matches(String word) {
        String[] segments = word.split("z");
        for (String segment : segments) {
            if (countVowels(segment) == 2)
                return true;
        }
        return false;
    }

    static int countMatches(String[] sentence) {
        int sum = 0;
        for (String word : sentence) {
            sum += matches(word) ? 1 : 0;
        }
        return sum;
    }

    public static void main(String[] args) {
        while (true) {
            String[] s = readSentence();
            if (Contains(s, "*"))
                break;
            int m = countMatches(s);
            System.out.println("Matching words = " + m);
        }
        System.out.println("Done");
    }
}