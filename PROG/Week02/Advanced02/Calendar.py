def read_date():
    data = input().split()
    # either there are 3 elements, or the 4th element is a weekday
    data[:3] = [int(i) for i in data[:3]]
    return data


class AngelaDate:
    """This class functions as a container for an Angela date. It handles
    calculations between them."""

    d: int
    m: int
    y: int

    def __init__(self, d, m, y) -> None:
        self.d = d
        self.m = m
        self.y = y

    def subtract(self, other: "AngelaDate"):
        """Subtracts another AngelaDate from this one, and returns the
        difference in days. If the other date is in the past, the days will be
        positive, otherwise they will be negative."""
        dy = self.y - other.y
        dm = self.m - other.m
        dd = self.d - other.d
        dm += dy * 15
        dd += dm * 30
        return dd


days = ["monday", "tuesday", "wednesday", "thursday", "friday"]


def main():
    d1, m1, y1, day = read_date()
    day = day.lower()  # they really did troll me with that one
    d2, m2, y2 = read_date()
    day_i = days.index(day)

    cur = AngelaDate(d1, m1, y1)
    oth = AngelaDate(d2, m2, y2)
    diff = oth.subtract(cur)
    # gets an "absolute" day, then figures where in the 5-day cycle it lands.
    oth_day = days[(day_i + diff) % 5]
    print(day_i)
    print(diff)
    print(oth_day.capitalize())


if __name__ == "__main__":
    main()
