import java.util.HashMap;
import java.util.Map;

public class NumberToWords {
    static Map<Integer, String> ones_word = new HashMap<Integer, String>() {
        {
            put(1, "one");
            put(2, "two");
            put(3, "three");
            put(4, "four");
            put(5, "five");
            put(6, "six");
            put(7, "seven");
            put(8, "eigth");
            put(9, "nine");
        }
    };
    static Map<Integer, String> tens_word = new HashMap<Integer, String>() {
        {
            put(1, "ten");
            put(2, "twenty");
            put(3, "thirty");
            put(4, "forty");
            put(5, "fifty");
            put(6, "sixty");
            put(7, "seventy");
            put(8, "eighty");
            put(9, "ninety");
        }
    };
    static Map<Integer, String> teens_word = new HashMap<Integer, String>() {
        {
            put(10, "ten");
            put(11, "eleven");
            put(12, "twelve");
            put(13, "thirteen");
            put(14, "fourteen");
            put(15, "fifteen");
            put(16, "sixteen");
            put(17, "seventeen");
            put(18, "eighteen");
            put(19, "nineteen");
        }
    };

    public static String intToWords(int num) {
        String word = "";
        int hundreths = num / 100;
        int tens = (num / 10) % 10;
        int ones = num % 10;
        int teen = num % 100;

        if (hundreths != 0) {
            word += ones_word.get(hundreths) + " hundred ";
            if (tens != 0 || ones != 0)
                word += " and ";
        }

        if (tens > 1)
            word += " " + tens_word.get(tens) + " ";

        if (tens == 1)
            word += " " + teens_word.get(teen) + " ";

        if (ones != 0 && tens != 1)
            word += " " + ones_word.get(ones) + " ";

        if (word == "")
            word = "zero";

        return word.replaceAll(" +", " ").trim();
    }

    public static String intToRoman(int num) {
        String word = "";

        while (num > 0) {
            if (num >= 900) {
                word += "CM";
                num -= 900;
            } else if (num >= 500) {
                word += "D";
                num -= 500;
            } else if (num >= 400) {
                word += "CD";
                num -= 400;
            } else if (num >= 100) {
                word += "C";
                num -= 100;
            } else if (num >= 90) {
                word += "XC";
                num -= 90;
            } else if (num >= 50) {
                word += "L";
                num -= 50;
            } else if (num >= 40) {
                word += "XL";
                num -= 40;
            } else if (num >= 10) {
                word += "X";
                num -= 10;
            } else if (num >= 9) {
                word += "IX";
                num -= 9;
            } else if (num >= 5) {
                word += "V";
                num -= 5;
            } else if (num >= 4) {
                word += "IV";
                num -= 4;
            } else {
                word += "I";
                num -= 1;
            }
        }

        return word;
    }

    public static int readInt() {
        System.out.print("Number: ");
        return In.nextInt();
    }

    public static void main(String[] args) {
        int n;
        while ((n = readInt()) != -1) {
            String words = intToWords(n);
            String roman = intToRoman(n);
            System.out.println("In Words: " + words);
            System.out.println("In Roman: " + roman);
        }

        System.out.println("Done");
    }
}
