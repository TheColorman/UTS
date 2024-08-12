public class AverageValue {
	public static void main(String[] args) {
		int sum = 0;
		int count = 0;

		System.out.print("Value: ");
		int val = In.nextInt();
		while (val != -1) {
			sum += val;
			count++;
			System.out.print("Value: ");
			val = In.nextInt();
		}

		double avg = sum / (double) count;
		if (count != 0) {
			System.out.println("Average = " + avg);
		}
	}
}
