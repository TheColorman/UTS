import java.util.ArrayList;
import java.util.List;

public class AverageMiddle {
	public static void main(String[] args) {
		List<Integer> integers = new ArrayList<Integer>();

		System.out.print("Enter an integer (-1 to exit): ");
		int newInt = In.nextInt();
		while (newInt != -1) {
			integers.add(newInt);
			System.out.print("Enter an integer (-1 to exit): ");
			newInt = In.nextInt();
		}

		if (integers.size() < 4) {
			System.out.println("No average to display.");
			return;
		}
		int originalLength = integers.size();

		int minInt = Integer.MAX_VALUE;
		int maxInt = Integer.MIN_VALUE;
		int originalSum = 0;

		for (Integer integer : integers) {
			originalSum += integer;
			if (integer < minInt)
				minInt = integer;
			if (integer > maxInt)
				maxInt = integer;
		}
		
		integers.remove(integers.indexOf(minInt));
		integers.remove(integers.indexOf(maxInt));

		int tot = 0;
		int count = integers.size();
		for (Integer integer : integers) {
			tot += integer;
		}

		double avg = tot / (double) count;
		System.out.println("The middle average is: " + avg);
		if (originalSum % originalLength == 0) {
			System.out.println("The sum is divisible by count");
		} else {
			System.out.println("The sum is not divisible by count");
		}
	}
}
