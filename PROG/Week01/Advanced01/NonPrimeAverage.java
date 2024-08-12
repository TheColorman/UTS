import java.lang.Math;
import java.util.LinkedList;

public class NonPrimeAverage {
    public static boolean isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i < Math.floor(Math.sqrt(n))+1; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        LinkedList<Integer> ints = new LinkedList<>();

        while (true) {
            System.out.print("Enter an integer (-1 to exit): ");
            int i = In.nextInt();
            if (i == -1) {
                break;
            }
            ints.push(i);
        }

        LinkedList<Integer> nonPrimes = new LinkedList<>();
        for (Integer i : ints) {
            if (!isPrime(i)) {
                nonPrimes.push(i);
            }
        }
        
        if (nonPrimes.size() < 2) {
            System.out.println("No average to display.");
        } else {
            int sum = 0;
            for (Integer i : nonPrimes) {
                sum += i;
            }
            double avg = sum / (double) nonPrimes.size();
            System.out.println("Average of non-prime numbers: " + avg);
        }
    }
}