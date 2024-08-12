public class Calendar {
	public static AngelaDate readDate() {
		String[] input = In.nextLine().split(" ");
		int d = Integer.parseInt(input[0]);
		int m = Integer.parseInt(input[1]);
		int y = Integer.parseInt(input[2]);

		AngelaDate date = new AngelaDate(d, m, y);

		if (input.length > 3) {
			date.day = input[3].toLowerCase();
		}

		return date;
	}

	/**
	 * This class functions as a container for an Angela date. It handles
	 * calculations between them.
	 */
	public static class AngelaDate {
		int d, m, y;
		// Had to modify the origina Python code a bit because it originally returned a
		// list with mixed datatypes. This allows me to return an AngelaDate that
		// includes both the ints and a string.
		String day;

		public AngelaDate(int d, int m, int y) {
			this.d = d;
			this.m = m;
			this.y = y;
		}

		/**
		 * Subtracts another AngelaDate from this one, and returns the difference in
		 * days. If the other date is in the past, the days will be positive, otherwise
		 * they will be negative.
		 */
		public int subtract(AngelaDate other) {
			int dy = this.y - other.y;
			int dm = this.m - other.m;
			int dd = this.d - other.d;
			dm += dy * 15;
			dd += dm * 30;
			return dd;
		}
	}

	/**
	 * Gets the index of a string in a string array. Wasn't sure how to do it and
	 * didn't want to google it, so here's my suboptimal solution.
	 */
	public static int indexOf(String[] arr, String val) {
		for (int i = 0; i < arr.length; i++) {
			if (arr[i].equals(val))
				return i;
		}
		return -1;
	}

	static String[] days = { "monday", "tuesday", "wednesday", "thursday", "friday" };

	public static void main(String[] args) {
		AngelaDate cur = readDate();
		AngelaDate oth = readDate();
		int day_i = indexOf(days, cur.day);
		int diff = oth.subtract(cur);

		// Fix posible negative indices
		int newDayIndex = (day_i + diff) % 5;
		if (newDayIndex < 0)
			newDayIndex += 5;

		String oth_day = days[newDayIndex];
		String oth_day_cap = oth_day.substring(0, 1).toUpperCase() + oth_day.substring(1);
		System.out.println(oth_day_cap);
	}
}